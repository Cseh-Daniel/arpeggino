#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {

  pinMode(23, OUTPUT);
 digitalWrite(23, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(23, !digitalRead(23));
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}