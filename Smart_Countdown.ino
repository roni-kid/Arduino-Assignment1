const int startValue = 5;
const int ledPin = 13;

void flashLED(int times) {
  int i = times;  
  
  while (i > 0) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
    i = i - 1;
  }
}

void setup() {
  int count = startValue; 

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("\n=== Smart Countdown Starting ===");

  while (count > 0) {
    Serial.print("Count: ");
    Serial.println(count);
    flashLED(count);
    delay(1000);
    count = count - 1;
  
}

  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(ledPin, LOW);
  Serial.println( "=== Countdown Complete ===" );
}


void loop() {
  // empty
}
