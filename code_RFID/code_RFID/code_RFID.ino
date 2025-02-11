#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above
Servo myservo; 
int BELL_PIN = A5;
long teststr;

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup() 
{
    pinMode(BELL_PIN, OUTPUT);
    SPI.begin();        // Init SPI bus
    mfrc522.PCD_Init(); // Init MFRC522 card
    Serial.begin(9600); // Initialize serial communications with the PC
}
void loop() {


 while (Serial.available()) 
    {
        teststr = Serial.read();  //read until timeout
        Serial.print(teststr);
    }
    if(teststr=='1')
    {
    digitalWrite(BELL_PIN, HIGH);
      delay(50);
      digitalWrite(BELL_PIN, LOW);
      delay(50);
      digitalWrite(BELL_PIN, HIGH);
      delay(50);
      digitalWrite(BELL_PIN, LOW);
    myservo.attach(3);
    myservo.write(0);
    teststr="";
    delay(3000);
    myservo.write(90);
    pinMode(3, OUTPUT);
    digitalWrite(3, LOW);
    }

        
        // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;
    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

      Serial.print("ci"); /*Xu dung cho xe vao*/
      //Serial.print("co");   /*Xu dung cho xe ra*/
      Serial.print(mfrc522.uid.uidByte[0], HEX);
      Serial.print(mfrc522.uid.uidByte[1], HEX);
      Serial.print(mfrc522.uid.uidByte[2], HEX);
      Serial.println(mfrc522.uid.uidByte[3], HEX);
      digitalWrite(BELL_PIN, HIGH);
      delay(50);
      digitalWrite(BELL_PIN, LOW);
      delay(50);
      digitalWrite(BELL_PIN, HIGH);
      delay(50);
      digitalWrite(BELL_PIN, LOW);
      delay(2000);
}
