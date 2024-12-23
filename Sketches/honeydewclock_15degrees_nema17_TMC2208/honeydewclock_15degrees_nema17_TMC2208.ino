#include <AccelStepper.h>
 
// Define stepper pins
#define STEP_PIN 3      // Step pin
#define DIR_PIN 2       // Direction pin
 
// Microstepping control pins
#define MS1_PIN 7
#define MS2_PIN 6
 
// Steps per revolution for the motor (full steps)
const float stepsPerRevolution = 200;

// Microstepping multiplier (1, 2, 4, 8, 16, or 32)
int microstepSetting = 2;

// AccelStepper instance in driver mode
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

// How many steps for a 15° move?
//  - 1 full revolution = 360°
//  - with microstepSetting, total steps/rev = stepsPerRevolution * microstepSetting
//  - 15° is (15/360) of a full revolution
//    => stepsFor15Deg = (15/360) * (stepsPerRevolution * microstepSetting)
int stepsFor15Deg;  

void setup() {
  // Set microstepping pins as outputs
  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);

  // Configure microstepping: for "2" microsteps, typically MS1=HIGH, MS2=LOW
  // (This can vary by board; adjust if needed)
  digitalWrite(MS1_PIN, HIGH);
  digitalWrite(MS2_PIN, LOW);

  // Calculate how many steps equals 15°
  stepsFor15Deg = int( 
    ((15.0 / 360.0) * (stepsPerRevolution * microstepSetting)) + 0.5 
  );
  
  // Set some reasonable speed/acceleration so the move happens smoothly
  // (Not too high, not too low)
  stepper.setMaxSpeed(300.0);       // steps/sec (adjust as desired)
  stepper.setAcceleration(100.0);   // steps/sec^2
}

void loop() {
  static long currentPosition = 0;
  
  // 1) Move the motor by 15°
  currentPosition += stepsFor15Deg;              // increment our target by 15°
  stepper.runToNewPosition(currentPosition);     // blocking move to that position
  
  // 2) Wait 1 minute (60,000 ms)
  delay(10000); 
}
