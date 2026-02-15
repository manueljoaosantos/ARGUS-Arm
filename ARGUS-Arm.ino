#include <Servo.h>

Servo servoBase;
Servo servoOmbro;
Servo servoCotovelo;
Servo servoGarra;

// ---- LIMITES ----
const int ombroMin = 25;   
const int ombroMax = 60;

const int cotoveloRecolhido = 30;
const int cotoveloEstendido = 90;

const int baseCenter = 90;
const int baseLeft   = 25;
const int baseRight  = 155;

const int garraAberta = 40; 
const int garraFechada = 90;

const int ledPin = 13;

// ---- VELOCIDADE ----
const int velocidadeServo = 70;
const int alivioTorque = 2;

// ---- POSIÇÕES REAIS ATUAIS ----
int posBaseAtual;
int posOmbroAtual;
int posCotoveloAtual;
int posGarraAtual;

// ======================================================
// 🔧 FUNÇÃO GENÉRICA COM CONTROLO REAL DE POSIÇÃO
// ======================================================
void moveServoProtegido(Servo &s, int &posAtual, int destino) {

  int step = (destino > posAtual) ? 1 : -1;

  while (posAtual != destino) {
    posAtual += step;
    s.write(posAtual);
    delay(velocidadeServo);
  }

  // 🔒 Alívio de torque controlado
  int posAlivio = posAtual - (step * alivioTorque);

  if (posAlivio < 0) posAlivio = 0;
  if (posAlivio > 180) posAlivio = 180;

  s.write(posAlivio);
  posAtual = posAlivio;
}

// ======================================================
// SETUP
// ======================================================
void setup() {

  pinMode(ledPin, OUTPUT);

  // Tempo para ligar bateria
  for (int i = 0; i < 20; i++) {
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  }

  servoBase.attach(2);
  servoOmbro.attach(3);
  servoCotovelo.attach(4);
  servoGarra.attach(5); 

  // Inicializa posições reais
  posBaseAtual = baseCenter;
  posOmbroAtual = ombroMin;
  posCotoveloAtual = cotoveloRecolhido;
  posGarraAtual = garraAberta;

  servoBase.write(posBaseAtual);
  servoOmbro.write(posOmbroAtual);
  servoCotovelo.write(posCotoveloAtual);
  servoGarra.write(posGarraAtual);

  delay(1500);
}

// ======================================================
// LOOP PRINCIPAL ESTÁVEL
// ======================================================
void loop() {

  // =========================
  // 🔹 1️⃣ CENTRO
  // =========================

  // Compacta
  moveServoProtegido(servoOmbro, posOmbroAtual, ombroMin);
  moveServoProtegido(servoCotovelo, posCotoveloAtual, cotoveloRecolhido);
  delay(300);

  // Estende
  moveServoProtegido(servoCotovelo, posCotoveloAtual, cotoveloEstendido);
  delay(300);

  // Desce
  moveServoProtegido(servoOmbro, posOmbroAtual, ombroMax);
  delay(500);

  // 🔹 FECHA (apanha)
  moveServoProtegido(servoGarra, posGarraAtual, garraFechada);
  delay(500);

  // Sobe com objeto
  moveServoProtegido(servoOmbro, posOmbroAtual, ombroMin);
  delay(400);


  // =========================
  // 🔹 2️⃣ ESQUERDA
  // =========================

  // Compacta antes de rodar
  moveServoProtegido(servoCotovelo, posCotoveloAtual, cotoveloRecolhido);
  delay(300);

  moveServoProtegido(servoBase, posBaseAtual, baseLeft);
  delay(500);

  // Estende
  moveServoProtegido(servoCotovelo, posCotoveloAtual, cotoveloEstendido);
  delay(300);

  // Desce
  moveServoProtegido(servoOmbro, posOmbroAtual, ombroMax);
  delay(500);

  // 🔹 ABRE (larga)
  moveServoProtegido(servoGarra, posGarraAtual, garraAberta);
  delay(500);

  // Sobe novamente
  moveServoProtegido(servoOmbro, posOmbroAtual, ombroMin);
  delay(400);


  // =========================
  // 🔹 3️⃣ DIREITA
  // =========================

  moveServoProtegido(servoCotovelo, posCotoveloAtual, cotoveloRecolhido);
  delay(300);

  moveServoProtegido(servoBase, posBaseAtual, baseRight);
  delay(500);

  moveServoProtegido(servoCotovelo, posCotoveloAtual, cotoveloEstendido);
  delay(300);

  moveServoProtegido(servoOmbro, posOmbroAtual, ombroMax);
  delay(500);

  // 🔹 FECHA novamente
  moveServoProtegido(servoGarra, posGarraAtual, garraFechada);
  delay(500);

  moveServoProtegido(servoOmbro, posOmbroAtual, ombroMin);
  delay(400);

  // =========================
  // 🔹 VOLTA AO CENTRO
  // =========================

  moveServoProtegido(servoCotovelo, posCotoveloAtual, cotoveloRecolhido);
  delay(300);

  moveServoProtegido(servoBase, posBaseAtual, baseCenter);
  delay(800);

  // Abre para reiniciar ciclo
  moveServoProtegido(servoGarra, posGarraAtual, garraAberta);
  delay(1500);
}
