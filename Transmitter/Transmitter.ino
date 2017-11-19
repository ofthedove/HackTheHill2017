#include <VirtualWire.h>
#include <VirtualWire_Config.h>

const int PIR_PIN = A3;
const int LED_PIN = 13;
const int TX_PIN = 12;

char *controller;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(TX_PIN, OUTPUT);
  
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(TX_PIN);
  vw_setup(4000); // speed of data transfer Kbps
}

void loop() {
  bool motionDetected = digitalRead(PIR_PIN);
  
  if (motionDetected)
  {
    controller="1";
  } else {
    controller="0";
  }
  
  digitalWrite(LED_PIN, motionDetected);
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
}
