// transmissor.ino
#define BAUD_RATE 9600
#define PINO_TX 17
#define PINO_RX 16

void setup() {
  Serial.begin(115200);
  Serial2.begin(BAUD_RATE, SERIAL_8N1, PINO_RX, PINO_TX);
  Serial.println("Transmissor pronto.");
}

void loop() {
  String mensagem = "DADO:" + String(millis());  // Ex: DADO:3042
  Serial2.println(mensagem);
  Serial.println("Enviado: " + mensagem);
  delay(1000);
}
