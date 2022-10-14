#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>


OneWire oneWire(A5); //Podłączenie do A5
DallasTemperature sensors(&oneWire); //Przekazania informacji do biblioteki
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int czujnik = A1;
int wejscie_cap = A2;
int wejscie_coil = A3;

void setup(void) {
  Serial.begin(9600);
  sensors.begin(); //Inicjalizacja czujnikow
  lcd.begin(16, 2);
}
 
void loop(void) {
  int war =analogRead(czujnik);
  int war_cap = analogRead(wejscie_cap);
  int war_coil = analogRead(wejscie_coil);
  Serial.print(war);
  //Serial.println();
  Serial.print(";");
  sensors.requestTemperatures(); //Pobranie temperatury czujnika
  Serial.print(sensors.getTempCByIndex(0));  //Wyswietlenie informacji
  Serial.print(";");
  Serial.println(); 
  lcd.setCursor(0, 0);
  lcd.print(war_cap);
  if (war_cap<1000) {
    lcd.print(' ');
  }
  lcd.setCursor(0, 1);
  lcd.print(war_coil);
  if (war_coil<1000) {
    lcd.print(' ');
  }
  //lcd.print("Temperatura:");
  //lcd.setCursor(5, 1);
  //lcd.print(sensors.getTempCByIndex(0));
  //lcd.print(" st. C");
  //lcd.print("Slonce: ");
  //if (war < 100) {
  //  lcd.print("0");
  //}
  //lcd.print(war);
  
  //lcd.setCursor(0, 1);
  //lcd.print("Temp: ");
  //lcd.print(sensors.getTempCByIndex(0));
  //lcd.print(" oC");
  delay(50);
}
