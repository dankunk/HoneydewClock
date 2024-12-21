// Pin assignments (adjust to match your wiring)
const int stepPin     = 2;
const int dirPin      = 3;
const int enablePin   = 4;  // or tie EN to GND directly if you like

// Movement parameters
const int microstepsPerMove = 133;      // ~15 degrees
const long moveDurationMs    = 10000;   // 10 seconds
const long waitDurationMs    = 3600000; // 1 hour = 3600 seconds * 1000 ms

void setup() {
  // Set pin modes
  pinMode(stepPin,   OUTPUT);
  pinMode(dirPin,    OUTPUT);
  pinMode(enablePin, OUTPUT);

  // Enable the driver (active low on many boards; set LOW to enable)
  digitalWrite(enablePin, LOW);

  // Set direction (HIGH or LOW depending on which way you want to rotate)
  digitalWrite(dirPin, LOW);

  // Optionally, you can test a small move here in setup
  // to ensure that everything is wired correctly.
}

void loop() {
  // 1) Move the motor by 15 degrees over 10 seconds

  // We have microstepsPerMove steps in total for this motion.
  // We'll spread them evenly over moveDurationMs = 10000 ms.
  for(int i = 0; i < microstepsPerMove; i++) {
    // Pulse the step pin
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(5);          // short pulse
    digitalWrite(stepPin, LOW);

    // How long to wait between pulses to reach 10s total?
    // Each pulse is one microstep, so we want 10,000 ms / 133 ~ 75 ms
    // We'll do the delay in milliseconds:
    delay(75);
  }

  // 2) Wait for 1 hour
  delay(waitDurationMs);

  // After the wait, loop() repeats, so it will do the move again,
  // hour after hour, for as long as the Arduino is powered or
  // connected to the computer.
  // TO-DO- configure the loop to stop after 24 iterations with a conditional statement and a counter
}
