/ *
Cet exemple stocke le premier numéro de carte lu dans une variable
En commençant par l'approche d'une carte, une comparaison est faite entre la valeur lue de la carte et la valeur stockée.
Les informations sont affichées sur un écran 16x2 via une communication I2C.
*/

// bibliotecas
#include <SPI.h>  // arduino standard
#include <MFRC522.h>  // besoin d'ajouter dans le dossier des bibliothèques arduino
#include <Wire.h> // arduino standard
#include <LiquidCrystal_I2C.h> // besoin d'ajouter dans le dossier des bibliothèques arduino

LiquidCrystal_I2C lcd(0x27,16,2);
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);    // créez un int MFRC522 portant le nom mfrc522
int *aux;
int card1[4];
int flag = 0;
int led = 13;
int cnt =0;

#define RED 4
#define GREEN 3

void setup() {
        pinMode(led, OUTPUT);
        
        lcd.init();
        lcd.backlight();
    SPI.begin();        // Init SPI bus
    mfrc522.PCD_Init();    // Init MFRC522 card
        lcd.print(" Approche de la carte");
        lcd.setCursor(0,1);
        lcd.print(" Pour l'acces  ");
        pinMode(RED,OUTPUT);
        pinMode(GREEN,OUTPUT);
}

void loop() {
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
        return;
    }

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
    }

    // Now a card is selected. The UID and SAK is in mfrc522.uid.
    
    // Dump UID
    
    for (byte i = 0; i < mfrc522.uid.size; i++) {
            aux[i]= mfrc522.uid.uidByte[i];
    } 
           if(flag == 0)
           {
             lcd.clear();
             lcd.print("   Card UID:    ");
             lcd.setCursor(0,1);
             for (byte i = 0; i < mfrc522.uid.size; i++) {
               card1[i] = aux[i];
             lcd.print( card1[i], DEC);
             lcd.print( " ");
             flag =1;
            }
           delay(3000);
           lcd.clear();
           lcd.print(" Approche de la carte");
           lcd.setCursor(0,1);
           lcd.print("  Pour l'acces   ");
           } 

           else{
            
           
             for (byte i = 0; i < mfrc522.uid.size; i++) {
               if(aux[i] == card1[i])
                cnt++;
             }
                            
            if(cnt == mfrc522.uid.size-1)
            {
              lcd.clear();
              lcd.print("     ACCES     ");
              lcd.setCursor(1,1);
              lcd.print("   AUTORISE    ");
              digitalWrite(GREEN, HIGH);
              delay(2000);
              digitalWrite(GREEN, LOW);
              
             }
             else
             {
              lcd.clear();
              lcd.print("     ACCES     ");
              lcd.setCursor(0,1);
              lcd.print("     REFUSR     ");
              digitalWrite(RED, HIGH);
              delay(2000);
              digitalWrite(RED, LOW);
             }
             
           }
           
           lcd.clear();
           lcd.print(" Approche de la carte");
           lcd.setCursor(0,1);
           lcd.print("  Pour l'acces   ");
  cnt=0;
}
