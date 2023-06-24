#include <SoftwareSerial.h>
SoftwareSerial espSerial(5, 6); // Rx,TX

String mood = "0";

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);
  pinMode(4, OUTPUT);
}

void loop() {
  if (espSerial.available()) { // Check if there's any data available to read
    mood = espSerial.readStringUntil('\n'); // Read the incoming data until newline character
    mood.trim(); // Remove any trailing whitespace or newline characters
    Serial.println(mood);
    if (mood == "1") {
      digitalWrite(4, LOW);
      Serial.println("Relay activated");
    }
    else {
      digitalWrite(4, HIGH);
      Serial.println("Relay deactivated");
    }
  }
}
