#include <AUnit.h>

// Test to check a simple assertion
test(correct) {
  int x = 1;
  assertEqual(x, 1);
}

// Test that is expected to fail
test(incorrect) {
  int x = 1;
  assertNotEqual(x, 1);
}

// Setup function
void setup() {
  // Initiaze the serial output
  Serial.begin(9600);
  while (! Serial);
}

// Loop function - runs the tests and blinks the LED
void loop() {
  // Run the aunit unit tests
  aunit::TestRunner::run();
}