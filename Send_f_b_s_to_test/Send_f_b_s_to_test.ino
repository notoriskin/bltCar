#include <SoftwareSerial.h>

// Bluetooth pins
SoftwareSerial btSerial(10, 11); // RX, TX

// Motor driver pins
#define IN1 5
#define IN2 6

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600); // HC-05 default baud rate
}

void loop() {
  if (btSerial.available()) {
    char command = btSerial.read();
    Serial.print("Received: ");
    Serial.println(command);

    switch (command) {
      case 'f': // Forward
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        break;
      case 'b': // Backward
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        break;
      case 's': // Stop
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        break;
      default:
        break;
    }
  }
}