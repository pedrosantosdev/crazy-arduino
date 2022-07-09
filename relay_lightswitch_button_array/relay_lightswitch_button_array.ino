const int QTY_RELAY_LIGHTSWITCH = 2;
const int INDEX_RELAY = 0;
const int INDEX_LIGHTSWITCH = 1;
const int INDEX_BUTTON = 2;
// Pin Number Relay, Lightswitch, Button
const int pinRelayLightSwitchArray[QTY_RELAY_LIGHTSWITCH][3] = {{2, 12, 10}, {3, 13, 9}};
bool statusRelayArray[QTY_RELAY_LIGHTSWITCH];
bool statusLightSwitchArray[QTY_RELAY_LIGHTSWITCH];

void setup() {
  for (int i = 0; i < QTY_RELAY_LIGHTSWITCH; ++i) {

    pinMode(pinRelayLightSwitchArray[i][INDEX_RELAY], OUTPUT); // RELAY
    pinMode(pinRelayLightSwitchArray[i][INDEX_LIGHTSWITCH], INPUT_PULLUP); // LIGHT_SWITCH
    pinMode(pinRelayLightSwitchArray[i][INDEX_BUTTON], INPUT_PULLUP); // BUTTON

    statusLightSwitchArray[i] = digitalRead(pinRelayLightSwitchArray[i][INDEX_LIGHTSWITCH]);
    statusRelayArray[i] = statusLightSwitchArray[i];

    digitalWrite(pinRelayLightSwitchArray[i][INDEX_RELAY], statusRelayArray[i]); // RELAY, STATUS
  }
}
void loop() {
  for (int i = 0; i < QTY_RELAY_LIGHTSWITCH; ++i) {
    if (digitalRead(pinRelayLightSwitchArray[i][INDEX_LIGHTSWITCH]) != statusLightSwitchArray[i]) {
      statusLightSwitchArray[i] = !statusLightSwitchArray[i];
      toggleRelay(i);
    } else if (digitalRead(pinRelayLightSwitchArray[i][INDEX_BUTTON]) == LOW) {
      toggleRelay(i);
    }
  }
};

void toggleRelay(int index) {
  statusRelayArray[index] = !statusRelayArray[index];
  digitalWrite(pinRelayLightSwitchArray[index][INDEX_RELAY], statusRelayArray[index]);
  delay(240);
}
