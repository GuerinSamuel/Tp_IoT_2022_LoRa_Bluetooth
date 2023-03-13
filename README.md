TP IoT et Réseaux Adaptés
===========

# Organisation

Dans le cadre de ce projet, deux approches seront adoptées. Tout d'abord la partie Publisher puis la partie Subscriber.
Deux groupes vont collaborer, chacun mettant en place l'une de ces parties.

Le groupe responsable de la partie Publisher est composé de Vicor Clairgeaux, Vincent Flageul et Samuel Guérin. 
Le groupe responsable de la partie Subscriber est composé de Lou Lécrivain et Edgar Croüs et est disponible [ici] (https://github.com/loulecrivain/iot_srt5).

# Première étape
La première étape consiste à permettre la communciation via le Wi-Fi entre les deux ESP32 puis d'envoyer les paramètres LoRa en utilisant le broker MQTT. Enfin, il faudra envoyer/recevoir des données en passant par cette connexion LoRa.
Etapes réalisées :
- [x] connexion à un AP wifi et sub ou pub sur le topic MQTT srt/lesbv
- [x] mise en place de la logique d'échange d'informations structurées de paramétrage LoRa via la librairie Json
- [x] configuration de LoRa
- [x] envoi de messages sur LoRa

# Deuxième étape
La deuxième étape consiste à supprimer la partie LoRA pour la remplacer par du Bluetooth Low Energy.
L'utilisation du BLE nécessite l'ajout de librairies prennant beaucoup d'espace ce qui entraine l'erreur suivante :
"Text section exceeds available space in boardLe croquis utilise 1349206 octets (102%) de l'espace de stockage de programmes. Le maximum est de 1310720 octets."
Pour remedier à ce problème, il faudra utiliser la bibliothèque [NimBLE] (https://github.com/h2zero/NimBLE-Arduino).
