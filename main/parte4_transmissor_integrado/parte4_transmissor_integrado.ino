#define BAUD_RATE 9600
#define PINO_TX 17
#define PINO_RX 16
#define PINO_POT 34

void setup() {
  Serial.begin(115200);
  Serial2.begin(BAUD_RATE, SERIAL_8N1, PINO_RX, PINO_TX);

  Serial.println("Transmissor Parte 4 pronto.");
  Serial.println("Lendo potenciometro no GPIO34 e enviando via UART2.");
}

void loop() {
  int leitura = analogRead(PINO_POT);   // 0 a 4095
  String mensagem = "ADC:" + String(leitura);

  Serial2.println(mensagem);
  Serial.println("Enviado: " + mensagem);

  delay(200);
}
