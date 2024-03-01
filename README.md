## Fonctionalitées

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
Voici une section sur le matériel utilisé que vous pouvez ajouter au README pour le projet :

---

## Matériel Utilisé

Pour réaliser ce projet de station météo connectée, vous aurez besoin des composants suivants :

1. **Microcontrôleur Arduino** : C'est le cerveau de notre projet qui gère la lecture des capteurs, le contrôle de l'affichage LCD et la communication Wi-Fi.

2. **Capteur DHT11** : Ce capteur est utilisé pour mesurer la température et l'humidité de l'air. Il est facile à utiliser avec Arduino et fournit des informations essentielles pour notre station météo.

3. **Photo-résistor** : Il s'agit d'une résistance dont la valeur change avec l'intensité lumineuse. Dans ce projet, il est utilisé pour mesurer le niveau de lumière ambiant.

4. **Buzzer** : Un petit haut-parleur qui émet un signal sonore lorsque la température dépasse un certain seuil. Cela sert d'alarme pour les conditions de température élevée.

5. **Écran LCD** : Un écran à cristaux liquides (Liquid Crystal Display) pour afficher les valeurs de température, d'humidité et de lumière mesurées par les capteurs.

6. **Résistances** : Vous aurez besoin de quelques résistances pour le photo-résistor et potentiellement pour le LCD, selon votre montage.

7. **Câbles de Connexion** : Câbles pour connecter tous les composants entre eux et avec la carte Arduino.

8. **Plaque de Prototypage (Breadboard)** : Une plaque de prototypage sans soudure pour assembler facilement le circuit sans avoir besoin de souder.
