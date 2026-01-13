#include <Arduino.h>
#include <RCSwitch.h>

#define SYSTEM_NAME    "HomeNode"
#define SYSTEM_VERSION "0.4"

#define RF_DATA_PIN     3
#define RF_DEBOUNCE_MS  500

// Relés ativos em LOW
const uint8_t relayPins[4] = {8, 9, 10, 11};
bool relayState[4] = {false, false, false, false};

// RF
RCSwitch rf = RCSwitch();
unsigned long lastCode = 0;
unsigned long lastTime = 0;

// Códigos RF (mapeados)
const unsigned long rfCodes[4] = {
  14732513, // BTN 1
  14732514, // BTN 2
  14732516, // BTN 3
  14732520  // BTN 4
};

void setupRelays() {
  for (uint8_t i = 0; i < 4; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], HIGH); // desligado (ativo em LOW)
  }
}

void toggleRelay(uint8_t index) {
  relayState[index] = !relayState[index];
  digitalWrite(relayPins[index], relayState[index] ? LOW : HIGH);

  Serial.print("[RELAY ");
  Serial.print(index + 1);
  Serial.print("] ");
  Serial.println(relayState[index] ? "ON" : "OFF");
}

void handleRF(unsigned long code) {
  for (uint8_t i = 0; i < 4; i++) {
    if (code == rfCodes[i]) {
      toggleRelay(i);
      return;
    }
  }

  Serial.print("[UNKNOWN RF] ");
  Serial.println(code);
}

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println();
  Serial.println("================================");
  Serial.println("   HomeNode - 4ch RF Relay");
  Serial.print("   Version: ");
  Serial.println(SYSTEM_VERSION);
  Serial.println("================================");

  setupRelays();
  rf.enableReceive(digitalPinToInterrupt(RF_DATA_PIN));
}

void loop() {
  if (rf.available()) {
    unsigned long code = rf.getReceivedValue();
    unsigned long now = millis();

    if (code != lastCode || (now - lastTime) > RF_DEBOUNCE_MS) {
      handleRF(code);
      lastCode = code;
      lastTime = now;
    }

    rf.resetAvailable();
  }
}
