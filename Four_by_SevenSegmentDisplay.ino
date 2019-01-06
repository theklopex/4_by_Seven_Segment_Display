// Public Domain
//
// Use at your own risk!
//
// Have a nice day!

// whatwilldadmando.wordpress.com

// Counts down on a four-digit seven-segment display.
// Based on using the Four-bit digital tube from the UNIROI Complete Arduino Kit for Beginner.
// Only tested on an Arduino Uno.

// Cathodes
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int dp = 8;

// Anodes
int d4 = 9;
int d3 = 10;
int d2 = 11;
int d1 = 12;

float startFloatNum = 120.0;
unsigned int startIntNum = 10000;
unsigned long startTime;

void setup() {
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);

  startTime = millis();
}

void showZero(bool showDecimal)
{
  // Default is to have decimal off
  int decimalValue = HIGH;
  if (showDecimal)
  {
    decimalValue = LOW;
  }
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp, decimalValue);
}

void showOne(bool showDecimal)
{
  // Default is to have decimal off
  int decimalValue = HIGH;
  if (showDecimal)
  {
    decimalValue = LOW;
  }
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, decimalValue);
}

void showTwo(bool showDecimal)
{
  // Default is to have decimal off
  int decimalValue = HIGH;
  if (showDecimal)
  {
    decimalValue = LOW;
  }
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp, decimalValue);
}

void showThree(bool showDecimal)
{
  // Default is to have decimal off
  int decimalValue = HIGH;
  if (showDecimal)
  {
    decimalValue = LOW;
  }
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp, decimalValue);
}

void showFour(bool showDecimal)
{
  // Default is to have decimal off
  int decimalValue = HIGH;
  if (showDecimal)
  {
    decimalValue = LOW;
  }
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, decimalValue);
}

void showFive(bool showDecimal)
{
  // Default is to have decimal off
  int decimalValue = HIGH;
  if (showDecimal)
  {
    decimalValue = LOW;
  }
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, decimalValue);
}

void showSix(bool showDecimal)
{
  // Default is to have decimal off
  int decimalValue = HIGH;
  if (showDecimal)
  {
    decimalValue = LOW;
  }
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, decimalValue);
}

void showSeven(bool showDecimal)
{
  // Default is to have decimal off
  int decimalValue = HIGH;
  if (showDecimal)
  {
    decimalValue = LOW;
  }
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, decimalValue);
}

void showEight(bool showDecimal)
{
  // Default is to have decimal off
  int decimalValue = HIGH;
  if (showDecimal)
  {
    decimalValue = LOW;
  }
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, decimalValue);
}

void showNine(bool showDecimal)
{
  // Default is to have decimal off
  int decimalValue = HIGH;
  if (showDecimal)
  {
    decimalValue = LOW;
  }
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, decimalValue);
}

void clearLEDs()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, HIGH);
}

int stallTime = 0;

// the loop function runs over and over again forever
void loop() {
  //countDownFloat();
  //countDownInt();
  timerCountdown(startFloatNum);
}

float timeRemaining = 0xffff;
void timerCountdown(float numSeconds)
{
  unsigned long nowTime;
  float endTime;
  float floatSeconds;

  endTime = startTime + (numSeconds * 1000.0);

  nowTime = millis();
  if (timeRemaining > 0)
  {
    timeRemaining = endTime - nowTime;
  }
  else
  {
    timeRemaining = 0;
  }
  floatSeconds = ((float)timeRemaining) / 1000.0;

//  displayInt(int(timeRemaining), 0);
  displayFloat(floatSeconds);
}

float myIntNumber = startIntNum;
void countDownInt()
{
  if (stallTime < 20)
  {
    stallTime++;
    delay(1);
  }
  else
  {
    myIntNumber -= 1;
    stallTime = 0;
  }

  displayInt(myIntNumber, 0);

  if (myIntNumber < 0)
  {
    myIntNumber = startIntNum;
  }    
}

float myFloatNumber = startFloatNum;
void countDownFloat()
{
  if (stallTime < 20)
  {
    stallTime++;
    delay(1);
  }
  else
  {
    myFloatNumber -= .1;
    stallTime = 0;
  }

  displayFloat(myFloatNumber);

  if (myFloatNumber < 0.001)
  {
    myFloatNumber = startFloatNum;
  }  
}

void port(unsigned char n)
{
  switch(n)
  {
    case 1:
      digitalWrite(d1, HIGH);
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      digitalWrite(d4, LOW);
      break;
    case 2:
      digitalWrite(d1, LOW);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, LOW);
      digitalWrite(d4, LOW);
      break;
    case 3:
      digitalWrite(d1, LOW);
      digitalWrite(d2, LOW);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, LOW);
      break;
    case 4:
      digitalWrite(d1, LOW);
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      digitalWrite(d4, HIGH);
      break;
    default:
      digitalWrite(d1, LOW);
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      digitalWrite(d4, LOW);
      break;
  }
}

void pickNumber(unsigned char n, bool showDecimal)
{
  switch(n)
  {
    case 0:
      showZero(showDecimal);
      break;
    case 1:
      showOne(showDecimal);
      break;
    case 2:
      showTwo(showDecimal);
      break;
    case 3:
      showThree(showDecimal);
      break;
    case 4:
      showFour(showDecimal);
      break;
    case 5:
      showFive(showDecimal);
      break;
    case 6:
      showSix(showDecimal);
      break;
    case 7:
      showSeven(showDecimal);
      break;
    case 8:
      showEight(showDecimal);
      break;
    case 9:
      showNine(showDecimal);
      break;
    default:
      clearLEDs();
      break;
  }
}

void displayFloat(float number)
{
  // Determine where to place the decimal.
  int intNumber = int(number);
  unsigned char significantDigits;
  unsigned char decimalPosition;

  // Remove one order of magnitude by dividing by zero and starting with significantDigits=1
  // This will guarantee that it will end with 0.000 instead of .0000 (which will not be able to display the decimal point.  It will be pretty!
  intNumber = intNumber / 10;
  for (significantDigits=1; significantDigits<5; significantDigits++)
  {
    if (intNumber > 0)
    {
      intNumber = intNumber / 10;
    }
    else
    {
      break;
    }
  }
  decimalPosition = 4 - significantDigits;

  for (int i = decimalPosition; i > 0; i--)
  {
    number = number * 10;
  }

  displayInt(int(number), decimalPosition);
}

void displayInt(unsigned int number, unsigned char decimalPosition)
{
  // The four positions are p4, p3, p2, p1
  // decimal position:
  //   p1 = 0
  //   p2 = 1
  //   p3 = 2
  //   p4 = 3
  //   nowhere = other

  unsigned char ones;
  unsigned char tens;
  unsigned char hundreds;
  unsigned char thousands;

  ones = number % 10;
  number = number / 10;
  tens = number % 10;
  number = number / 10;
  hundreds = number % 10;
  number = number / 10;
  thousands = number % 10;
  
  displayPos(1, thousands, decimalPosition==3);
  displayPos(2, hundreds, decimalPosition==2);
  displayPos(3, tens, decimalPosition==1);
  displayPos(4, ones, decimalPosition==0);
}

void displayPos(unsigned char x, unsigned char number, bool showDecimal)
{
  port(x);
  pickNumber(number, showDecimal);
  delay(1);
  clearLEDs();
}

