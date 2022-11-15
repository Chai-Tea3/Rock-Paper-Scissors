#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins.
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int buzz = 7;
int rLed = 6;
int gLed = 5;
int bLed = 4;
int rButton = 3;
int gButton = 2;
int bButton = A5;//Extra button.
int rVal;
int gVal;
int bVal;
long lastPress;
long thresh = 100;

// Game Variables
int humanWins = 0;
int arduinoWins = 0;
long arduinoChoice;


void setup() {
  // Set up the LCD's number of columns and rows:
  pinMode(buzz, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(bLed, OUTPUT);
  pinMode(rButton, INPUT);
  pinMode(gButton, INPUT);
  pinMode(bButton, INPUT);
  Serial.begin(9600);// For diagnostics while you're building the game.
  lcd.begin(16, 2);
  lastPress = millis();// Initialize to current clock time.
  lcd.setCursor(3, 0);
  lcd.print("Rock Paper");
  lcd.setCursor(4, 1);
  lcd.print("Scissors");

  randomSeed(analogRead(0));
  arduinoChoice = random(3);

  // Cycle the Leds 
  delay(250);
  digitalWrite(rLed, HIGH);
  delay(250);
  digitalWrite(gLed, HIGH);
  delay(250);
  digitalWrite(bLed, HIGH);
  delay(250);
  digitalWrite(rLed, LOW);
  delay(250);
  digitalWrite(gLed, LOW);
  delay(250);
  digitalWrite(bLed, LOW);
  lcd.clear();

  // Sound to indicate a new round.
  tone(buzzer, 1000);
  delay(1000);
  noTone(buzzer);

  lcd.print("Throw Down Now!");

}

void loop() {
  // Read the button pin values.
  rVal = digitalRead(rButton);
  gVal = digitalRead(gButton);
  bVal = analogRead(bButton);


  // Rock Button
  if (rVal == HIGH && millis() - lastPress > thresh) {
    if (arduinoChoice == 0) { // Rock
      digitalWrite(rLed, HIGH);
      lcd.clear();
      lcd.print("Tie!");
    }
    else if (arduinoChoice == 1) { // Paper
      digitalWrite(gLed, HIGH);
      lcd.clear();
      lcd.print("Arduino Wins!");
      arduinoWins++;
    }
    else if (arduinoChoice == 2) { // Scissors
      digitalWrite(bLed, HIGH);
      lcd.clear();
      lcd.print("Human Wins!");
      humanWins++;
    }
    delay(500);
    digitalWrite(rLed, LOW);
    digitalWrite(gLed, LOW);
    digitalWrite(bLed, LOW);
    lcd.clear();
    lcd.print("Human: ");
    lcd.print(humanWins);
    lcd.setCursor(0, 1);
    lcd.print("Arduino: ");
    lcd.print(arduinoWins);
    delay(250);
    digitalWrite(rLed, HIGH);
    delay(250);
    digitalWrite(gLed, HIGH);
    delay(250);
    digitalWrite(bLed, HIGH);
    delay(250);
    digitalWrite(rLed, LOW);
    delay(250);
    digitalWrite(gLed, LOW);
    delay(250);
    digitalWrite(bLed, LOW);
    lcd.clear();
    lcd.print("Throw Down Now!");


    arduinoChoice = random(3);
    lastPress = millis();
  }
  // Paper Button
  if (gVal == HIGH && millis() - lastPress > thresh) {
    if (arduinoChoice == 0) { // Rock
      digitalWrite(rLed, HIGH);
      lcd.clear();
      lcd.print("Human Wins!");
      humanWins++;
    }
    else if (arduinoChoice == 1) { // Paper
      digitalWrite(gLed, HIGH);
      lcd.clear();
      lcd.print("Tie!");
    }
    else if (arduinoChoice == 2) { // Scissors
      digitalWrite(bLed, HIGH);
      lcd.clear();
      lcd.print("Arduino Wins!");
      arduinoWins++;
    }
    delay(500);
    digitalWrite(rLed, LOW);
    digitalWrite(gLed, LOW);
    digitalWrite(bLed, LOW);
    lcd.clear();
    lcd.print("Human: ");
    lcd.print(humanWins);
    lcd.setCursor(0, 1);
    lcd.print("Arduino: ");
    lcd.print(arduinoWins);
    delay(250);
    digitalWrite(rLed, HIGH);
    delay(250);
    digitalWrite(gLed, HIGH);
    delay(250);
    digitalWrite(bLed, HIGH);
    delay(250);
    digitalWrite(rLed, LOW);
    delay(250);
    digitalWrite(gLed, LOW);
    delay(250);
    digitalWrite(bLed, LOW);
    lcd.clear();
    lcd.print("Throw Down Now!");


    arduinoChoice = random(3);
    lastPress = millis();
  }
  // Scissors Button
  if (bVal > 500 && millis() - lastPress > thresh) {
    if (arduinoChoice == 0) { // Rock
      digitalWrite(rLed, HIGH);
      lcd.clear();
      lcd.print("Arduino Wins!");
      arduinoWins++;
    }
    else if (arduinoChoice == 1) { // Paper
      digitalWrite(gLed, HIGH);
      lcd.clear();
      lcd.print("Human Wins!");
      humanWins++;
    }
    else if (arduinoChoice == 2) { // Scissors
      digitalWrite(bLed, HIGH);
      lcd.clear();
      lcd.print("Tie!");
    }
    delay(500);
    digitalWrite(rLed, LOW);
    digitalWrite(gLed, LOW);
    digitalWrite(bLed, LOW);
    lcd.clear();
    lcd.print("Human: ");
    lcd.print(humanWins);
    lcd.setCursor(0, 1);
    lcd.print("Arduino: ");
    lcd.print(arduinoWins);
    delay(250);
    digitalWrite(rLed, HIGH);
    delay(250);
    digitalWrite(gLed, HIGH);
    delay(250);
    digitalWrite(bLed, HIGH);
    delay(250);
    digitalWrite(rLed, LOW);
    delay(250);
    digitalWrite(gLed, LOW);
    delay(250);
    digitalWrite(bLed, LOW);
    lcd.clear();
    lcd.print("Throw Down Now!");


    arduinoChoice = random(3);
    lastPress = millis();
  }
}
