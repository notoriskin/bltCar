void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    if (c == '1') {
      digitalWrite(7, HIGH);
      Serial.println("LED ON");
    } else if (c == '0') {
      digitalWrite(7, LOW);
      Serial.println("LED OFF");
    }
  }
}