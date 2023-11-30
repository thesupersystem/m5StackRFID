#include <Wire.h>
#include "MFRC522_I2C.h" //rfid library
#include <M5CoreS3.h>

#define RST_PIN 0

MFRC522_I2C mfrc522(0x28,RST_PIN); 

void setup() {
    M5.begin(true, true, false);  
    M5.Lcd.setTextSize(2); 
    M5.Lcd.print("\nRFID WriterZ\n");      
    M5.Lcd.print("\nCode written by: \nthesupersystem\n");
    M5.Lcd.print("\n\Tap card ");

    Wire.begin(2,1);
    mfrc522.PCD_Init();


}

void loop() {
  M5.Lcd.setCursor(40, 47);
  // Look for new cards
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.println("Card detected!");

    // Create a data buffer
    byte data[] = "Video1";

  // Write data to block 1
    boolean result = mfrc522.MIFARE_Write(1, data, sizeof(data));

    if (result) {
      M5.Lcd.fillRect(0, 0, 320, 240, BLACK);
      M5.Lcd.println("Data written successful");
      M5.Lcd.println("\nData Written: Video1");
    } else {
      M5.Lcd.println("Error writing data to the card.");
    }

    delay(2000);  // Delay to avoid multiple writings
  }

}
