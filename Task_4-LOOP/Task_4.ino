int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== Countdown beginning ===");

  int counter = 10;

  while (counter > 0) {
    Serial.print("Counter is: ");
    Serial.println(counter);
    delay(1000);
    counter = counter - 2;
  }

  Serial.println("Liftoff!");

  int flashes = 3;
  while (flashes > 0) {
    digitalWrite(ledPin, HIGH); delay(200);
    digitalWrite(ledPin, LOW);  delay(200);
    flashes = flashes - 1;
}
}

void loop() {
  // empty
}