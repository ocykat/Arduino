#include <SoftwareSerial.h>

const byte rxPin = 2; // Wire this to Rx Pin of ESP8266
const byte txPin = 3; // Wire this to Tx Pin of ESP8266
const int BAUDRATE = 9600;

// We'll use a software serial interface to connect to ESP8266
SoftwareSerial ESP8266 (txPin, rxPin);

void setup() {
    Serial.begin(BAUDRATE);
    ESP8266.begin(BAUDRATE); // Change this to the baudrate used by ESP8266
    delay(1000); // Let the module self-initialize
}

void loop() {
    Serial.println("Sending an AT command...");
    ESP8266.println("AT");
    delay(1000);
    while (ESP8266.available()){
        String inData = ESP8266.readStringUntil('\n');
        Serial.println("Got reponse from ESP8266: " + inData);
    }  
}
