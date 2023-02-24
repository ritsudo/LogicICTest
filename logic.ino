#define X1 2 //OPERAND A
#define X2 3 //OPERAND B
#define Y 4  //GATE OUTPUT

byte testPattern[4][2] = {
  {0,0},
  {1,0},
  {0,1},
  {1,1}};

byte resultPattern[4] = {0, 0, 0, 0};

char names[8][4] = {
  {'E', 'R', 'R', '1'},
  {'E', 'R', 'R', '2'},
  {'A', 'N', 'D'},
  {'N', 'A', 'N', 'D'},
  {'O', 'R'},
  {'N', 'O', 'R'},
  {'X', 'O', 'R'},
  {'X', 'N', 'O', 'R'}};

byte results[8][4] = {
  {0, 0, 0, 0},
  {1, 1, 1, 1},
  {0, 0, 0, 1},
  {1, 1, 1, 0},
  {0, 1, 1, 1},
  {1, 0, 0, 0},
  {0, 1, 1, 0},
  {1, 0, 0, 1}};

int compareResult(byte result[4]) {
  char compareCounter;
  char cOut = 0;

  for (int c = 0; c < 8; c++) {
    compareCounter = 0;
    for (int d = 0; d < 4; d++) {
      if (result[d] == results[c][d]) {
        compareCounter += 1;
      }
    }
    if (compareCounter == 4) {
      cOut = c;
    }
  }

  if (cOut != 0) {
    return cOut;
  } else {
    return 0;
  }
}

void setup() {
  pinMode(X1, OUTPUT);
  pinMode(X2, OUTPUT);
  pinMode(Y, INPUT);
  
  Serial.begin(9600);
  Serial.print("\nLogic gate test: ");

  for (int z = 0; z < 4; z++) {
    digitalWrite(X1, testPattern[z][0]);
    delay(1);
    digitalWrite(X2, testPattern[z][1]);
    delay(1);
    resultPattern[z] = digitalRead(Y);
    delay(1);
    Serial.print(digitalRead(Y));
  }

  //got resultPattern, required match
  
  char gateOut = compareResult(resultPattern);
  Serial.print("\nCorresponds to: ");

  for (int q = 0; q < 4; q++) {
    Serial.print(names[gateOut][q]);
  }
}

void loop() {
}
