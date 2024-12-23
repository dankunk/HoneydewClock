#define STEP_PIN 3
#define DIR_PIN 2

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  // Set direction
  digitalWrite(DIR_PIN, LOW); // or HIGH

  // Enable driver if needed
  // e.g. pinMode(EN_PIN, OUTPUT); digitalWrite(EN_PIN, LOW);
}

void loop() {
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(500);  // short pulse
  digitalWrite(STEP_PIN, LOW);
  delay(10);               // ~10ms between steps
}
