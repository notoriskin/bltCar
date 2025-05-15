#include <SoftwareSerial.h>

// Bluetooth pins
SoftwareSerial btSerial(10, 11); // RX, TX

// Drive motor (forward/backward)
#define IN1 5
#define IN2 6

// Steering motor (left/right pulse)
#define IN3 2
#define IN4 3

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600); // HC-05 default
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

      case 'l': // Turn left (pulse)
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        delay(300); // adjust pulse length to suit your gear motor
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;

      case 'r': // Turn right (pulse)
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        delay(300); // adjust as needed
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
    }
  }
}