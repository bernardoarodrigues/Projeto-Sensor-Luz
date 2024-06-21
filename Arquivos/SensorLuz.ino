/*
  Autor: Bernardo Alexandre Alves Rodrigues - 15442936
*/

// GPIOs
static const int rele = 8, ultraTrig = 9, ultraEcho = 10;

// Setup
void setup() {
  // Inicia Serial
  Serial.begin(9600);

  // Inicia GPIOs
  pinMode(rele, OUTPUT);
  pinMode(ultraTrig, OUTPUT);
  pinMode(ultraEcho, INPUT);

  // Desliga relé 
  digitalWrite(rele, HIGH);
}

// Loop
void loop() {
  // Emite onda pelo sensor ultrassônico
  digitalWrite(ultraTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultraTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraTrig, LOW);
  
  // Calcula tempo de demora para retorno da onda
  long duracao = pulseIn(ultraEcho, HIGH); 

  // Calcula a distância usando a velocidade do som (aproximadamente 343 m/s)
  float distancia = (duracao * 0.0343) / 2;
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Caso a distância captada seja menor do que 10cm, aciona o relé
  if(distancia < 10) digitalWrite(rele, LOW);
  // Caso contrário, desliga-o
  else digitalWrite(rele, HIGH);

  // Aguarda 500ms
  delay(500);
}