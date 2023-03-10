#include <Arduino.h>
//void ICACHE_RAM_ATTR ISRoutine (); only esp8266
void ISRoutine() {
  Serial.println("INTRERUPPT");
  digitalWrite(LED_BUILTIN, 1);
}

void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), ISRoutine, RISING);
  attachInterrupt(digitalPinToInterrupt(3), ISRoutine, CHANGE);
}

void loop() {
  digitalWrite(LED_BUILTIN, 0);
  delay(1000);
  Serial.println("normal_run");
  delay(1000);
}
