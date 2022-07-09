const int QTY_RELAY_LIGHTSWITCH = 2;
const int INDEX_RELAY = 0;
const int INDEX_LIGHTSWITCH = 1;
// Pin Number LightSwitch, Relay
const int pinRelayLightSwitchArray[QTY_RELAY_LIGHTSWITCH][2] = {{2, 13}, {3, 12}};
bool statusRelayArray[QTY_RELAY_LIGHTSWITCH];
bool statusLightSwitchArray[QTY_RELAY_LIGHTSWITCH];

void setup() {
  for (int i = 0; i < QTY_RELAY_LIGHTSWITCH; ++i) {

    pinMode(pinRelayLightSwitchArray[i][INDEX_RELAY], OUTPUT); // RELAY
    pinMode(pinRelayLightSwitchArray[i][INDEX_LIGHTSWITCH], INPUT_PULLUP); // LIGHT_SWITCH

    statusLightSwitchArray[i] = digitalRead(pinRelayLightSwitchArray[i][INDEX_LIGHTSWITCH]);
    statusRelayArray[i] = statusLightSwitchArray[i];

    digitalWrite(pinRelayLightSwitchArray[i][INDEX_RELAY], statusRelayArray[i]); // RELAY, STATUS
  }
}
void loop() {
  for (int i = 0; i < QTY_RELAY_LIGHTSWITCH; ++i) {
    if ((digitalRead(pinRelayLightSwitchArray[i][INDEX_LIGHTSWITCH]) != statusLightSwitchArray[i])) {
      statusRelayArray[i] = !statusRelayArray[i];
      statusLightSwitchArray[i] = !statusLightSwitchArray[i];
      digitalWrite(pinRelayLightSwitchArray[i][INDEX_RELAY], statusRelayArray[i]);
      delay(240);
    }
  }
};
