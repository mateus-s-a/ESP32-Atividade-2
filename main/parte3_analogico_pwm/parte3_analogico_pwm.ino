#define PINO_POT 34
#define PINO_LED 25
#define FREQ_PWM 1000
#define RESOLUCAO 8

void setup() {
  Serial.begin(115200);

  // Nova API do LEDC no Arduino-ESP32 atual
  ledcAttach(PINO_LED, FREQ_PWM, RESOLUCAO);
}

void loop() {
  int leitura = analogRead(PINO_POT);

  int pwm = map(leitura, 0, 4095, 0, 255);

  ledcWrite(PINO_LED, pwm);

  float tensao = leitura * (3.3 / 4095.0);

  Serial.print("ADC: ");
  Serial.print(leitura);
  Serial.print(" | V: ");
  Serial.print(tensao, 2);
  Serial.print(" | PWM: ");
  Serial.println(pwm);

  delay(200);
}
