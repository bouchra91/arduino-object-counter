#include <LiquidCrystal.h>

// Définition des broches du LCD
const int RS = 12;
const int E  = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 7;

// Variables
long duree;
float distance;
// Variable compteur
int compteur = 0;
bool objetPresent = false;


// Création de l'objet LCD
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);


void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 intro();
 
}
void intro(){
   // Initialisation du LCD
 lcd.begin(16, 2);

  // Effacer l'écran
  lcd.clear();

  // Afficher un message
  lcd.setCursor(0, 0);
  lcd.print("Bonjour");

  lcd.setCursor(0, 1);
  lcd.print("Arduino");

  delay(2000);

  lcd.clear();
}
void afficheur()
{
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Objet detecte :");

  lcd.setCursor(0,1);
  lcd.print(compteur);
}

void calcule_distance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duree = pulseIn(echoPin, HIGH, 30000); // timeout de 30 ms

  
 
  distance = duree * 0.0343 / 2;
    if (distance < 15)
{
   digitalWrite(ledPin, HIGH);   // Allumer la LED

    if (!objetPresent)
    {
        compteur++;
        objetPresent = true;
    }
}
else
{
   digitalWrite(ledPin, LOW);    // Éteindre la LED
    objetPresent = false;
}
  delay(1000);
}

void loop()
{
  
calcule_distance();
afficheur();



}