#include <VirtualWire.h>
#include <VirtualWire_Config.h>

const int LED_PIN = 13;

const int maxLightLevel = 145; // How bright the lights get
const int minLightLevel = 0;   // How dim the lights get
const int stepSizeup = 1;        // How long the lights take to change
const int stepSizedown = 7;        // How long the lights take to change
const int delayLen = 60;       // Also affects time take to change

int targetValue = 0;
int curValue = 0;

void setup()
{
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(12);
  vw_setup(4000);
  
  pinMode(LED_PIN, OUTPUT);

  vw_rx_start(); // Start the receiver PLL running
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    if(buf[0]=='1'){
      targetValue = maxLightLevel;
    }
    if(buf[0]=='0'){
      targetValue = minLightLevel;
    }
  }

  if (curValue < targetValue) {
    curValue += stepSizeup;
    if (curValue > targetValue) {
      curValue = targetValue;
    }
  }

  if (curValue > targetValue) {
    curValue -= stepSizedown;
    if (curValue < targetValue) {
      curValue = targetValue;
    }
  }

  analogWrite(LED_PIN, curValue);
  delay(delayLen);
}


