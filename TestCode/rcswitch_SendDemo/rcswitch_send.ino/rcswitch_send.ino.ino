#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  mySwitch.enableTransmit(10);  // Using Pin #10
  mySwitch.setPulseLength(189);
}

void loop() {
  mySwitch.send(4543795, 24); // outlet 1 on
  delay(2000);
  mySwitch.send(4543804, 24); // outlet 1 off
  delay(2000);
}
