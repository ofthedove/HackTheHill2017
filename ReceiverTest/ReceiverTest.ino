const int RX_PIN = A4;
const int LED_PIN = 3;

void setup() {
  pinMode(RX_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(RX_PIN));
  Serial.print("\n");
  delay(25);
}
