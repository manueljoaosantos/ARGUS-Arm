#include <Servo.h>

// =====================
// PIN LED
// =====================
const int ledPin = 13;

// =====================
// Estrutura de eixo
// =====================
struct ServoAxis {
  Servo servo;
  int posAtual;
  int destino;
  float velocidade;
  float acumulador;
  bool ativo;
};

// =====================
// LIMITES
// =====================
const int ombroMin = 25;
const int ombroMax = 60;

const int cotoveloRecolhido = 30;
const int cotoveloEstendido = 90;

const int baseCenter = 90;
const int baseLeft   = 25;
const int baseRight  = 155;

const int garraAberta  = 40;
const int garraFechada = 90;

// =====================
// EIXOS
// =====================
ServoAxis base;
ServoAxis ombro;
ServoAxis cotovelo;
ServoAxis garra;

// =====================
// Inicialização eixo
// =====================
void initAxis(ServoAxis &a, int pin, int posInicial) {
  a.servo.attach(pin);
  a.posAtual = posInicial;
  a.destino = posInicial;
  a.velocidade = 0;
  a.acumulador = 0;
  a.ativo = false;
  a.servo.write(posInicial);
}

// =====================
// Movimento sincronizado grupo
// =====================
void iniciarMovimentoGrupo(int tempoTotalMs) {

  int distBase = abs(base.destino - base.posAtual);
  int distOmbro = abs(ombro.destino - ombro.posAtual);
  int distCotovelo = abs(cotovelo.destino - cotovelo.posAtual);
  int distGarra = abs(garra.destino - garra.posAtual);

  int maxDist = max(max(distBase, distOmbro), max(distCotovelo, distGarra));
  if (maxDist == 0) return;

  float ciclos = tempoTotalMs / 10.0;

  base.velocidade      = (float)distBase / ciclos;
  ombro.velocidade     = (float)distOmbro / ciclos;
  cotovelo.velocidade  = (float)distCotovelo / ciclos;
  garra.velocidade     = (float)distGarra / ciclos;

  base.acumulador = 0;
  ombro.acumulador = 0;
  cotovelo.acumulador = 0;
  garra.acumulador = 0;

  base.ativo = distBase > 0;
  ombro.ativo = distOmbro > 0;
  cotovelo.ativo = distCotovelo > 0;
  garra.ativo = distGarra > 0;
}

// =====================
// Atualização não bloqueante
// =====================
void atualizarAxis(ServoAxis &a) {

  if (!a.ativo) return;
  if (a.posAtual == a.destino) {
    a.ativo = false;
    return;
  }

  a.acumulador += a.velocidade;

  while (a.acumulador >= 1.0) {
    a.acumulador -= 1.0;

    if (a.destino > a.posAtual)
      a.posAtual++;
    else
      a.posAtual--;

    a.servo.write(a.posAtual);

    if (a.posAtual == a.destino) {
      a.ativo = false;
      break;
    }
  }
}

// =====================
// Verifica movimento
// =====================
bool algumEixoAtivo() {
  return base.ativo || ombro.ativo || cotovelo.ativo || garra.ativo;
}

// =====================
// SETUP
// =====================
void setup() {

  pinMode(ledPin, OUTPUT);

  initAxis(base, 2, baseCenter);
  initAxis(ombro, 3, ombroMin);
  initAxis(cotovelo, 4, cotoveloRecolhido);
  initAxis(garra, 5, garraAberta);
}

// =====================
// Máquina de estados
// =====================
int estado = 0;
unsigned long ultimo = 0;
unsigned long ultimoLed = 0;
bool estadoLed = false;

// =====================
// LOOP
// =====================
void loop() {

  // Atualização servos a cada 10ms
  if (millis() - ultimo >= 10) {
    ultimo = millis();

    atualizarAxis(base);
    atualizarAxis(ombro);
    atualizarAxis(cotovelo);
    atualizarAxis(garra);
  }

  // =====================
  // LED
  // =====================
  if (algumEixoAtivo()) {
    if (millis() - ultimoLed >= 200) {
      ultimoLed = millis();
      estadoLed = !estadoLed;
      digitalWrite(ledPin, estadoLed);
    }
  } else {
    digitalWrite(ledPin, HIGH);
  }

  // =====================
  // Máquina de estados
  // =====================
  switch (estado) {

    case 0:
      base.destino = baseCenter;
      ombro.destino = ombroMin;
      cotovelo.destino = cotoveloRecolhido;
      garra.destino = garraAberta;
      iniciarMovimentoGrupo(1500);
      estado = 1;
      break;

    case 1:
      if (!algumEixoAtivo()) {
        base.destino = baseLeft;
        ombro.destino = ombroMin;
        cotovelo.destino = cotoveloEstendido;
        iniciarMovimentoGrupo(2000);
        estado = 2;
      }
      break;

    case 2:
      if (!algumEixoAtivo()) {
        ombro.destino = ombroMax;
        garra.destino = garraFechada;
        iniciarMovimentoGrupo(1500);
        estado = 3;
      }
      break;

    case 3:
      if (!algumEixoAtivo()) {
        base.destino = baseCenter;
        ombro.destino = ombroMin;
        cotovelo.destino = cotoveloRecolhido;
        iniciarMovimentoGrupo(2000);
        estado = 4;
      }
      break;

    case 4:
      if (!algumEixoAtivo()) {
        base.destino = baseRight;
        ombro.destino = ombroMin;
        cotovelo.destino = cotoveloEstendido;
        iniciarMovimentoGrupo(2000);
        estado = 5;
      }
      break;

    case 5:
      if (!algumEixoAtivo()) {
        ombro.destino = ombroMax;
        garra.destino = garraAberta;
        iniciarMovimentoGrupo(1500);
        estado = 6;
      }
      break;

    case 6:
      if (!algumEixoAtivo()) {
        estado = 0;
      }
      break;
  }
}
