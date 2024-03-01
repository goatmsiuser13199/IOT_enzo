Ce code est destiné à être utilisé avec un microcontrôleur Arduino pour créer une station météo connectée qui mesure la température, l'humidité et le niveau de lumière. Voici les fonctionnalités principales :

1. **Capteurs et Affichage** :
   - Utilise un capteur DHT11 pour mesurer la température et l'humidité.
   - Utilise un photo-résistor pour mesurer le niveau de lumière.
   - Affiche les valeurs mesurées sur un écran LCD.

2. **Alarme de Température** :
   - Un buzzer est activé lorsque la température dépasse un seuil prédéfini (27°C par défaut).

3. **Connexion Wi-Fi** :
   - Se connecte à un réseau Wi-Fi spécifié.
   - Met en place un serveur web sur le microcontrôleur qui peut être accédé depuis un navigateur pour voir les mesures actuelles.

4. **Boucle Principale** :
   - Dans la boucle principale (`loop`), le code lit les valeurs des capteurs, met à jour l'affichage LCD, et vérifie s'il y a des clients connectés au serveur web pour leur envoyer les données actuelles en format HTML.

5. **Configuration et Sécurité** :
   - Les identifiants Wi-Fi sont configurés au début du script.
   - Utilise des délais pour gérer la connexion Wi-Fi et les intervalles de mesure.

Ce code est parfait pour un projet DIY de station météo à domicile, permettant à l'utilisateur de surveiller les conditions environnementales en temps réel tant localement (via l'écran LCD) que à distance (via le serveur web).
