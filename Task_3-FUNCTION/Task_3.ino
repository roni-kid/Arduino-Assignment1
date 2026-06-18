int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void blinkOnce(int onDuration, int offDuration) {
  digitalWrite(ledPin, HIGH);
  delay(onDuration);
  digitalWrite(ledPin, LOW);
  delay(offDuration);
}

// void blinkTwice(int waitTime) {
//   blinkOnce(waitTime);
//   blinkOnce(waitTime);
// }

void loop() {
  Serial.println("Fast blink");
  blinkOnce(100, 400);

  Serial.println("Medium blink");
  blinkOnce(300, 600);

  Serial.println("Slow blink");
  blinkOnce(800, 1300);

  delay(2000);

  // blinkTwice(200);
}