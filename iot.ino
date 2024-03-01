#include <SPI.h>
#include <WiFiNINA.h>
#include <DHT.h>
#include <LiquidCrystal.h> 

#define DHTPIN 13
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

#define BUZZER_PIN 8 // Définir la broche du buzzer
#define PHOTO_PIN A0 // Définir la broche du photo-résistor
float buzzerTempThreshold = 27.0; // Seuil initial pour le buzzer

char ssid[] = "Bah What le retour 3"; // Le SSID de votre réseau
char pass[] = "azertyuiop"; // Le mot de passe de votre réseau
int status = WL_IDLE_STATUS; 
WiFiServer server(80);

// Initialiser la bibliothèque LCD avec les numéros des broches d'interface
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2); // Configurer le nombre de colonnes et de lignes de l'écran LCD
  pinMode(BUZZER_PIN, OUTPUT); // Initialiser la broche de contrôle du buzzer en sortie
  pinMode(PHOTO_PIN, INPUT); // Initialiser la broche du photo-résistor en entrée

  // Tentative de connexion au réseau WiFi :
  while (status != WL_CONNECTED) {
    status = WiFi.begin(ssid, pass);
    delay(10000); // Attendre 10 secondes pour la connexion
  }
  server.begin(); // Démarrer le serveur

  lcd.print("Connexion..."); // Afficher le message de connexion sur l'écran LCD
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int lightLevel = analogRead(PHOTO_PIN); 

  Serial.print("Humidité : ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Température : ");
  Serial.print(temperature);
  Serial.print(" C\t");
  Serial.print("Niveau de lumière : ");
  Serial.println(lightLevel);

  if (temperature >= buzzerTempThreshold) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100); // Activer le buzzer pendant 100 millisecondes
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Mettre à jour l'affichage LCD avec les valeurs de température, d'humidité et de lumière
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print(" H:");
  lcd.print(humidity);
  lcd.setCursor(0, 1); 
  lcd.print("Lumière:");
  lcd.print(lightLevel);


  WiFiClient client = server.available(); 
  if (client) { 
    String currentLine = "";
    while (client.connected()) { // Boucler tant que le client est connecté
      if (client.available()) {
        char c = client.read(); 
        if (c == '\n') { 
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close"); 
            client.println("Refresh: 5");
            client.println();
            client.println("<!DOCTYPE HTML>");
            client.println("<html>");
            client.println("<p>Température : " + String(temperature) + " C</p>");
            client.println("<p>Humidité : " + String(humidity) + " %</p>");
            client.println("<p>Niveau de lumière : " + String(lightLevel) + "</p>");
            client.println("</html>");
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    delay(1); 
    client.stop(); // Fermer la connexion
  }
  delay(2000); // Courte pause entre les lectures
}