// receptor.ino
#define BAUD_RATE 9600
#define PINO_TX 17
#define PINO_RX 16
#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  Serial2.begin(BAUD_RATE, SERIAL_8N1, PINO_RX, PINO_TX);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Receptor pronto.");
}

void loop() {
  if (Serial2.available()) {
    String recebido = Serial2.readStringUntil('\n');
    Serial.println("Recebido: " + recebido);
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
  }
}
