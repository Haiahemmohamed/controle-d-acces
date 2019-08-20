# controle-d-acces

Dans cet exemple, la première carte est lue et son numéro de série est stocké dans une variable.
Ensuite, à l'approche d'une carte, celle-ci est lue et son numéro est comparé au numéro enregistré. S'ils sont identiques, le message "ACCESS RELEASED" s'affiche, sinon "ACCES REFUS".
Comme il s’agit d’un programme de test, je ne me suis pas inquiété du stockage non volatile du numéro de série de la carte valide. Pour une utilisation réelle, il sera nécessaire, par exemple, de changer le code afin de stocker le numéro de série de la carte "valide" dans la mémoire arduino eprom.

Matériel utilisé:

Module RFID MFRC522 (fiche technique)
Arduino UNO (similaire utilisé)
Ecran LCD 16x2 avec module I2C.
Sauteurs
