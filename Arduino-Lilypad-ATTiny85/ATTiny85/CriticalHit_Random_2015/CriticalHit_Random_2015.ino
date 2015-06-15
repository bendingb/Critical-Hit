/*Code for the random attiny45/85 chip in which random LED turns on
 */
//                        attiny45/85
//                   reset -+---+- power
//          (option 4) pb3 -+*  +- pb2 (option 3)
//      (switch input) pb4 -+   +- pb1 (option 2)
//                  ground -+---+- pb0 (option 1)
//               
//      when switch is pressed, all light up dimmly and when switch resleased, random light turns on
int ledNumber= 0;


void setup() {
  pinMode(0, OUTPUT);  
  pinMode(1, OUTPUT);  
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);  

  pinMode(4, INPUT);   // switch pin
  digitalWrite(4, HIGH);  // turn on pull-up resistor
}

void loop() {  
  int switchValue = digitalRead(4); // read the switch.  0 if closed, 1 if open

  if (switchValue == 0)
  {
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(ledNumber, HIGH);

    ledNumber++;

    if (ledNumber== 4)
    {
      ledNumber = 0;
    }
  }
}
