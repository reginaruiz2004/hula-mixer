/*
 * Hula Mixer - Motor Test Sketch
 * 
 * Validates L298N + NEMA17 wiring before full implementation.
 * Rotates motor one full revolution in a single direction, repeatedly.
 * 
 * Wiring: see docs/electronics.md
 */

#include <Stepper.h>

// Steps per revolution (200 steps = 1.8° per step, full-step mode)
const int stepsPerRevolution = 200;

// Pin order for Stepper object: IN1, IN3, IN2, IN4
// (library expects coil order, not L298N physical pin order)
Stepper myStepper(stepsPerRevolution, 9, 7, 8, 6);

const int ENA = 11;
const int ENB = 10;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  myStepper.setSpeed(60);
}

void loop() {
  myStepper.step(stepsPerRevolution);
  delay(1000);
}