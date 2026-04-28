#define BAUD_RATE 9600
#define PINO_TX 17
#define PINO_RX 16
#define PINO_LED 25
#define FREQ_PWM 1000
#define RESOLUCAO_PWM 8

void setup() {
  Serial.begin(115200);
  Serial2.begin(BAUD_RATE, SERIAL_8N1, PINO_RX, PINO_TX);

  // API atual do core ESP32 3.x+
  ledcAttach(PINO_LED, FREQ_PWM, RESOLUCAO_PWM);

  Serial.println("Receptor Parte 4 pronto.");
  Serial.println("Recebendo ADC via UART2 e controlando PWM no GPIO25.");
}

void loop() {
  if (Serial2.available()) {
    String recebido = Serial2.readStringUntil('\n');
    recebido.trim();

    if (recebido.startsWith("ADC:")) {
      String valorTexto = recebido.substring(4);
      int leituraADC = valorTexto.toInt();   // 0 a 4095

      if (leituraADC < 0) leituraADC = 0;
      if (leituraADC > 4095) leituraADC = 4095;

      int pwm = map(leituraADC, 0, 4095, 0, 255);

      // API atual do core ESP32 3.x+
      ledcWrite(PINO_LED, pwm);

      float tensao = leituraADC * (3.3 / 4095.0);

      Serial.print("Recebido: ");
      Serial.print(recebido);
      Serial.print(" | PWM: ");
      Serial.print(pwm);
      Serial.print(" | Tensao estimada: ");
      Serial.println(tensao, 2);
    }
  }
}
