// analogico_pwm.ino
#define PINO_POT 34
#define PINO_LED 25
#define CANAL_PWM 0
#define FREQ_PWM 1000  // Hz
#define RESOLUCAO 8    // bits → 0 a 255

void setup() {
  Serial.begin(115200);
  ledcSetup(CANAL_PWM, FREQ_PWM, RESOLUCAO);
  ledcAttachPin(PINO_LED, CANAL_PWM);
}

void loop() {
  int leitura = analogRead(PINO_POT);       // 0 a 4095 (12 bits)
  int pwm = map(leitura, 0, 4095, 0, 255);  // remapeia para 8 bits
  ledcWrite(CANAL_PWM, pwm);
  float tensao = leitura * (3.3 / 4095.0);
  Serial.print("ADC: ");
  Serial.print(leitura);
  Serial.print(" | V: ");
  Serial.print(tensao, 2);
  Serial.print(" | PWM: ");
  Serial.println(pwm);
  delay(200);
}
