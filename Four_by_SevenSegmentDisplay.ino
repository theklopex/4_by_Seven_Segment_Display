// Public Domain
// whatwilldadmando.wordpress.com

// Counts down on a four-digit seven-segment display.
// Based on using the Four-bit digital tube from the UNIROI Complete Arduino Kit for Beginner.

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
}

void showZero()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp, HIGH);
}

void showOne()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, HIGH);
}

void showTwo()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
}

void showThree()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
}

void showFour()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
}

void showFive()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
}

void showSix()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
}

void showSeven()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, HIGH);
}

void showEight()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
}

void showNine()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
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

unsigned int myNumber = 10000;
int stallTime = 0;

// the loop function runs over and over again forever
void loop() {
  unsigned int tempNumber = myNumber;
  unsigned char ones;
  unsigned char tens;
  unsigned char hundreds;
  unsigned char thousands;

  ones = tempNumber % 10;
  tempNumber = tempNumber / 10;
  tens = tempNumber % 10;
  tempNumber = tempNumber / 10;
  hundreds = tempNumber % 10;
  tempNumber = tempNumber / 10;
  thousands = tempNumber % 10;

  if (stallTime < 20)
  {
    stallTime++;
    delay(1);
  }
  else
  {
    myNumber -= 1;
    stallTime = 0;
  }

  displayPos(1,thousands);
  displayPos(2,hundreds);
  displayPos(3,tens);
  displayPos(4,ones);

  if (myNumber == 0)
  {
    myNumber = 10000;
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

void pickNumber(unsigned char n)
{
  switch(n)
  {
    case 0:
      showZero();
      break;
    case 1:
      showOne();
      break;
    case 2:
      showTwo();
      break;
    case 3:
      showThree();
      break;
    case 4:
      showFour();
      break;
    case 5:
      showFive();
      break;
    case 6:
      showSix();
      break;
    case 7:
      showSeven();
      break;
    case 8:
      showEight();
      break;
    case 9:
      showNine();
      break;
    default:
      clearLEDs();
      break;
  }
}

void displayPos(unsigned char x, unsigned char number)
{
  port(x);
  pickNumber(number);
  delay(1);
  clearLEDs();
}

