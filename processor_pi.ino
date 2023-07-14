// Bibliotecas necessárias
#include <Arduino.h>

// Pino do LED para indicar o processamento
const int ledPin = 13;

// Variável para contar o número de pontos dentro do círculo
long pontosNoCirculo = 0;

// Número total de pontos
const long totalPontos = 1000000;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
  
  // Define o pino do LED como saída
  pinMode(ledPin, OUTPUT);
  
  // Limpa o LED
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Início do cálculo
  unsigned long inicio = micros();

  // Loop para gerar pontos aleatórios e verificar se estão dentro do círculo
  for (long i = 0; i < totalPontos; ++i) {
    // Gera coordenadas aleatórias
    float x = random(0, 10000) / 10000.0;
    float y = random(0, 10000) / 10000.0;
    
    // Verifica se o ponto está dentro do círculo
    if (x * x + y * y <= 1) {
      pontosNoCirculo++;
    }
  }

  // Fim do cálculo
  unsigned long fim = micros();
  
  // Calcula o valor de Pi
  float pi = 4.0 * pontosNoCirculo / totalPontos;

  // Exibe o resultado no monitor serial
  Serial.print("Pi = ");
  Serial.print(pi, 10);
  Serial.print(" | Tempo: ");
  Serial.print((fim - inicio)/1000000);
  Serial.println(" segundos");
  
  // Pisca o LED para indicar que o cálculo foi concluído
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  
  // Reinicia as variáveis para o próximo cálculo
  pontosNoCirculo = 0;
  
  // Aguarda um tempo antes de realizar o próximo cálculo
  delay(3000);
}
