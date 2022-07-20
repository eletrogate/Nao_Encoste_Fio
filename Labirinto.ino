#include <LiquidCrystal.h>

// Definição de variáveis
#define wire 6
#define res 9
#define ledR 7
#define ledG 10
#define buz 8

// Declaração das variáveis do Display LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Atribuição dos pinos utilizados
  pinMode(wire, INPUT_PULLUP); // O fio está como pullup porque ele deve ser acionado quando for-lhe atribuído zero, ou seja, quando estiver conectado ao GND
  pinMode(res, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(buz, OUTPUT);
}

void loop() {
  // Inicialização do LCD
  lcd.begin(16, 2);

  // Variáveis internas do loop
  bool fio = 0;
  bool reset = 0;
  
  int mortes = 0;
  
  int ep = 1; // Variável "estado passado", necessária para que a contagem das mortes não seja errada
  
  lcd.print("Vamos jogar!"); // Escreve no LCD
  delay(800);
  lcd.clear();
  
  while(reset!=1){
    fio = digitalRead(wire); // A variável fio lê sua porta
    reset = digitalRead(res); // A variável reset lê sua porta
    lcd.print("Taca-lhe pau!!");
    lcd.setCursor(0,1);
    lcd.print("Mortes: ");
    lcd.print(mortes); // LCD exibe quantas vezes o jogador tocou no fio
    if (fio == LOW){ // Assim que o jogador encostar no fio...
      digitalWrite(ledR, HIGH); // Led vermelho acende
      digitalWrite(ledG, LOW); // Led verde apaga
      digitalWrite(buz, HIGH); // Buzzer emite som
      if (fio != ep && fio == LOW) // Verifica se o fio foi encostado e se seu estado mudou
        mortes++;
    }else{
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(buz, LOW);
    }
    ep = fio;
    lcd.setCursor(0,0);
  }
}