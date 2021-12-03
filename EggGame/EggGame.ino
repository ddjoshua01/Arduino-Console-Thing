#include <LedControl.h>
int dinPin = 13;
int clkPin = 11;
int csPin = 12;
bool conditional = true;
int score = 0;
int lives = 3;
bool gameOver = false;

LedControl lc1 = LedControl(dinPin,clkPin,csPin, 1);
int playerPosX = 1;
int playerPosY = 2;
int stickSWpin = 1;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(0, HIGH);
 pinMode(6,HIGH);
 int vrx = 2;
 lc1.shutdown(0, false);
 lc1.setIntensity(0,1);
 
}
float xvar = 7;
float otherxvar = 2;
float randY = random(1, 6);
float otherrandY = random(1, 6);
float increment = 0.1;
void loop() {
while (gameOver == false) {
 
  float xval = analogRead(2)/122;
  float yval = analogRead(3)/4;
  // put your main code here, to run repeatedly:
  if(yval >= 200) {
    playerPosY++;  
  }
  if(yval <= 100) {
    playerPosY--;  
  }

  if(playerPosY>=5) {
    playerPosY = 5;  
  }
  if(playerPosY<=0) {
    playerPosY = 0;  
  }
 
   
   
   
   lc1.setLed(0, playerPosX, playerPosY, conditional);
   lc1.setLed(0, playerPosX+1, playerPosY+2, conditional);
   lc1.setLed(0, playerPosX+1, playerPosY, conditional);
   lc1.setLed(0, playerPosX, playerPosY+1, conditional);
   lc1.setLed(0, playerPosX, playerPosY+2, conditional);
   lc1.setLed(0, playerPosX, playerPosY+2, conditional);
   lc1.setLed(0, xvar, randY, true);
   if(lives == 3) {
    lc1.setLed(0, 0, 7, true);
    lc1.setLed(0, 0, 6, true);
    lc1.setLed(0, 0, 5, true);
 

   
   }
     else if(lives == 2) {
    lc1.setLed(0, 0, 7, true);
    lc1.setLed(0, 0, 6, true);
     
     
   
   }
     else if(lives == 1) {
    lc1.setLed(0, 0, 7, true);
   
 



   }
   

 
   
   delay(100);
   lc1.setLed(0, playerPosX, playerPosY, false);
   lc1.setLed(0, playerPosX+1, playerPosY+2, false);
   lc1.setLed(0, playerPosX+1, playerPosY, false);
   lc1.setLed(0, playerPosX, playerPosY+1, false);
   lc1.setLed(0, playerPosX, playerPosY+2, false);
   lc1.setLed(0, playerPosX, playerPosY+2, false);
   lc1.setLed(0, xvar, randY, false);
   lc1.setLed(0, 0, 7, false);
    lc1.setLed(0, 0, 6, false);
    lc1.setLed(0, 0, 5, false);

   xvar=xvar-increment;
   
   if(xvar<=2 && randY == playerPosY+1) {
     xvar=7;
     randY = random(1, 6);
     score++;
     increment = increment+0.05;
     
   }
   if(xvar <=2 && randY != playerPosY+1) {
      xvar = 7;
      randY= random(1, 6);
      lives--;
      increment = increment+0.05;
   }
   if(lives <= 0) {
      gameOver=true;
   }
   
 

} if (gameOver == true) {
      lc1.setLed(0, 3, 4, true);
  }}

