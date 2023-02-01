/*
   "bel" pijl aanwijzer
*/

const uint8_t N_LAMPJES = 8;                                // De losse lampjes.
const uint8_t PIN_LAMPJE[N_LAMPJES] = {2, 3, 4, 5, 6, 7, 8, 9};
const uint8_t PIN_SENSOR = 10;
const uint32_t SPEED = 300;                                 // Tijd per stap in ms.

void setup() {
  for (uint8_t i = 0; i < N_LAMPJES; i++) {
    pinMode(PIN_LAMPJE[i], OUTPUT);
    digitalWrite(PIN_LAMPJE[i], LOW);
  }
}

void loop() {
  if (digitalRead(PIN_SENSOR)) {                            // Sensor output is actief HIGH
    for (uint8_t i = 0; i < N_LAMPJES; i++) {
      digitalWrite(PIN_LAMPJE[i], HIGH);
      delay(SPEED);
    }
    delay(SPEED);
    delay(SPEED);
    for (uint8_t i = 0; i < N_LAMPJES; i++) {
      digitalWrite(PIN_LAMPJE[i], LOW);
    }
    delay(SPEED);
  }
}
