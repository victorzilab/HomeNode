#include <Arduino.h>
#include <RCSwitch.h>

#define SYSTEM_NAME    "HomeNode"
#define SYSTEM_VERSION "0.3.1"

#define RF_DATA_PIN 3
#define RELAY_PIN   10   // relé ativo em LOW
#define RF_DEBOUNCE_MS 500

// Código RF do botão 3
#define BTN_3 14732516

RCSwitch rf = RCSwitch();

bool relayState = false;   // false = OFF | true = ON
unsigned long lastCode = 0;
unsigned long lastTime = 0;

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println();
  Serial.println("================================");
  Serial.println("   HomeNode - Single Relay");
  Serial.print("   Version: ");
  Serial.println(SYSTEM_VERSION);
  Serial.println("================================");

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // começa desligado (ativo em LOW)

  rf.enableReceive(digitalPinToInterrupt(RF_DATA_PIN));
}

void toggleRelay() {
  relayState = !relayState;
  digitalWrite(RELAY_PIN, relayState ? LOW : HIGH);

  Serial.print("[RELAY] ");
  Serial.println(relayState ? "ON" : "OFF");
}

void loop() {
  if (rf.available()) {
    unsigned long code = rf.getReceivedValue();
    unsigned long now = millis();

    if (code == BTN_3 &&
        (code != lastCode || (now - lastTime) > RF_DEBOUNCE_MS)) {

      toggleRelay();
      lastCode = code;
      lastTime = now;
    }

    rf.resetAvailable();
  }
}
