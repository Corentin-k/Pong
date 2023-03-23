#define joyX A0
#define joyY A1
#define joy2X A2
#define joy2Y A3

int firstPlayerBoard[5] = {140, 160, 180, 200, 220};
int secondPlayerBoard[5] = {159, 179, 199, 219, 239};
int avanceX = 0, avanceY = 1;
int ball = 189;
int firstMove = 0, secondMove = 0;

void setup() {
  Serial.begin(9600);
}

void setupLocation() {
  
}
 
void loop () {
  delay(500);
  moveBall();
  moveFirstPlayer();
  moveSecondPlayer();
  setupLocation();
}

void moveFirstPlayer() {
    readFirst();
    if(firstMove == 0) return;
    if(firstMove < 0) {
        if(firstPlayerBoard[4] == 380) return;
        int tempTab[5];
        for (int i = 0; i < 4; i++){ 
          firstPlayerBoard[i]= tempTab[i+1];
          }
        firstPlayerBoard[4] += 20;
        
    } else {
        if(firstPlayerBoard[0] == 0) return;
        int tempTab[5]=firstPlayerBoard;
  
        for (int i = 1; i < 4; i++){  firstPlayerBoard[i + 1]=tempTab[i];}
        
        firstPlayerBoard[0] -= 20;
    }
}

// void loop() {
  // // put your main code here, to run repeatedly:
  // int firstValue = analogRead(joyX);
  // int secondValue = analogRead(joy2X);
   
     
  // //print the values with to plot or view
  // Serial.print("firstValue :");
  // Serial.print(firstValue);

  // Serial.print(",\tsecondValue :");
  // Serial.print(secondValue);
  
  // Serial.print("\n");
  // delay(1000);
// }
