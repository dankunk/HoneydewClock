# HoneydewClock
- A repo for scripts and documentation for automated aphid honeydew clocks. 

- These honeydew clocks are built with off-the-shelf stepper motors and are controlled by arduino microcontrollers.

## Items needed:
- Constant Voltage DC power supply (with over current protection; 0-30v and 0-10A variable DC power supply is more than enough).
- 1x NEMA-17 bipolar stepper motor with breakout cable (I am using the 17HS19-2004S1 from StepperOnline).
- 1x TMC2208 v2.0 Stepper motor driver (the cheap ones on amazon should be OK; just be sure it has the potentiometer and screw driver for setting vRef).
- Multimeter (for setting vRef; a cheap one should do just fine, ~$20).
- 1x 100uF or 1x 47uF capacitor.
- Breakout Cables (assorted colors and sizes to keep things clean and organized)
- Arduino Uno with the provided USB cable (once things are programmed, the arduino can be powered from the 12v rail on the breadboard into the Vin on the arduino).
