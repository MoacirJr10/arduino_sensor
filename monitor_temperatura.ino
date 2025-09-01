#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// ===== Configuração da tela OLED =====
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ===== Configuração do sensor DHT11 =====
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ===== Pinos dos LEDs =====
#define LED_VERDE   8
#define LED_AMARELO 9
#define LED_VERMELHO 10

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    for(;;); 
  }

  dht.begin();

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20);
  display.println("Iniciando...");
  display.display();
  delay(2000);
}

void loop() {
  delay(2000);

  float temp = dht.readTemperature();

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Monitor de Temp");

  if (isnan(temp)) {
    display.setTextSize(2);
    display.setCursor(10, 25);
    display.println("Falha!");
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
  } else {
    display.setTextSize(2);
    display.setCursor(0, 25);
    display.print(temp, 1);
    display.println(" C");

    // ===== Lógica corrigida =====
    if (temp < 25) {
      digitalWrite(LED_VERDE, HIGH);
      digitalWrite(LED_AMARELO, LOW);
      digitalWrite(LED_VERMELHO, LOW);
    } 
    else if (temp >= 25 && temp < 30) {
      digitalWrite(LED_VERDE, LOW);
      digitalWrite(LED_AMARELO, HIGH);
      digitalWrite(LED_VERMELHO, LOW);
    } 
    else if (temp >= 30) {
      digitalWrite(LED_VERDE, LOW);
      digitalWrite(LED_AMARELO, LOW);
      digitalWrite(LED_VERMELHO, HIGH);
    }
  }

  display.display();
}
