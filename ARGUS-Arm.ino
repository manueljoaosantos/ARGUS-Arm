#include <Servo.h>

Servo servoBase;
Servo servoOmbro;
Servo servoCotovelo;
Servo servoGarra;

// ---- OMBRO ----
const int ombroMin = 5;      // alto
const int ombroMax = 50;     // baixo

// ---- COTOVELO ----
const int cotoveloRecolhido = 30;
const int cotoveloEstendido = 90;

// ---- BASE ----
const int baseCenter = 90;
const int baseLeft   = 45;
const int baseRight  = 135;

// ---- GARRA ----
const int garraAberta  = 40;
const int garraFechada = 90;

int pos;

void setup() {
  delay(10000);
  servoBase.attach(2);
  servoOmbro.attach(3);
  servoCotovelo.attach(5);
  servoGarra.attach(4);

  // posição inicial segura
  servoBase.write(baseCenter);
  servoOmbro.write(ombroMin);
  servoCotovelo.write(cotoveloRecolhido);
  servoGarra.write(garraAberta);

  delay(1500);
}

void loop() {

  // 1️⃣ Ombro sobe
  for (pos = ombroMax; pos >= ombroMin; pos--) {
    servoOmbro.write(pos);
    delay(30);
  }

  delay(300);

  // 2️⃣ Cotovelo estende
  for (pos = cotoveloRecolhido; pos <= cotoveloEstendido; pos++) {
    servoCotovelo.write(pos);
    delay(25);
  }

  delay(300);

  // 3️⃣ Base para direita (+45°)
  for (pos = baseCenter; pos <= baseRight; pos++) {
    servoBase.write(pos);
    delay(25);
  }

  delay(400);

  // 4️⃣ Garra fecha (apanha)
  servoGarra.write(garraFechada);
  delay(800);

  // 5️⃣ Base para esquerda (-90° total)
  for (pos = baseRight; pos >= baseLeft; pos--) {
    servoBase.write(pos);
    delay(25);
  }

  delay(400);

  // 6️⃣ Garra abre (larga)
  servoGarra.write(garraAberta);
  delay(800);

  // 7️⃣ Base volta ao centro
  for (pos = baseLeft; pos <= baseCenter; pos++) {
    servoBase.write(pos);
    delay(25);
  }

  delay(400);

  // 8️⃣ Cotovelo recolhe
  for (pos = cotoveloEstendido; pos >= cotoveloRecolhido; pos--) {
    servoCotovelo.write(pos);
    delay(25);
  }

  delay(300);

  // 9️⃣ Ombro desce
  for (pos = ombroMin; pos <= ombroMax; pos++) {
    servoOmbro.write(pos);
    delay(45);
  }

  delay(2500);
}
