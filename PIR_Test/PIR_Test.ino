const int PIR_PIN = 2;
const int LED_PIN = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, digitalRead(PIR_PIN));
}
