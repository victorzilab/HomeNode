#include <Arduino.h>
#include <RCSwitch.h>

#define SYSTEM_NAME    "HomeNode"
#define SYSTEM_VERSION "0.1"

#define RF_DATA_PIN 3

RCSwitch rf = RCSwitch();

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println();
  Serial.println("================================");
  Serial.println("   HomeNode - RF Sniffer");
  Serial.print("   Version: ");
  Serial.println(SYSTEM_VERSION);
  Serial.println("================================");
  Serial.println("Listening RF on pin 3...");
  Serial.println();

  rf.enableReceive(digitalPinToInterrupt(RF_DATA_PIN));
}

void loop() {
  if (rf.available()) {
    unsigned long value = rf.getReceivedValue();

    if (value == 0) {
      Serial.println("[RF] Unknown encoding");
    } else {
      Serial.print("[RF] Code: ");
      Serial.print(value);

      Serial.print(" | Bits: ");
      Serial.print(rf.getReceivedBitlength());

      Serial.print(" | Protocol: ");
      Serial.print(rf.getReceivedProtocol());

      Serial.print(" | Pulse: ");
      Serial.println(rf.getReceivedDelay());
    }

    rf.resetAvailable();
  }
}
