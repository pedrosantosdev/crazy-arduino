const int QTY_RELAY_BUTTON= 2;
const int INDEX_RELAY= 0;
const int INDEX_BUTTON = 1;
// Pin Number Button, Relay
const int pinRelayButtonArray[QTY_RELAY_BUTTON][2] = {{2, 9}, {3, 10}};
bool statusRelayArray[QTY_RELAY_BUTTON] = {false, false};

void setup() {
  for (int i = 0; i < QTY_RELAY_BUTTON; ++i) {
    pinMode(pinRelayButtonArray[i][INDEX_RELAY], OUTPUT); // RELAY
    pinMode(pinRelayButtonArray[i][INDEX_BUTTON], INPUT_PULLUP); // BUTTON
    digitalWrite(pinRelayButtonArray[i][INDEX_RELAY], statusRelayArray[i]); // RELAY, STATUS
  }
}
void loop() {
  for (int i = 0; i < QTY_RELAY_BUTTON; ++i) {
    if ((digitalRead(pinRelayButtonArray[i][INDEX_BUTTON]) == LOW)) {
      statusRelayArray[i] = !statusRelayArray[i];
      digitalWrite(pinRelayButtonArray[i][INDEX_RELAY], statusRelayArray[i]);
      delay(240);
    }
  }
};
