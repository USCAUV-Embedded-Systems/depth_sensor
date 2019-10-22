IntervalTimer myTimer;
const int ledPin = LED_BUILTIN;  // the pin with a LED
int inPin= A17;
volatile int flag;
int count;
int count_enable;
void setup() {
  // put your setup code here, to run once:
  count=0;
  count_enable=0;
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
  Serial.begin(9600);
}
void inter_routine() {
  if(digitalRead(ledPin)==LOW) 
    digitalWrite(ledPin, HIGH);
  else 
    digitalWrite(ledPin, LOW);
  flag=1;
}
void loop() {
  // put your main code here, to run repeatedly:
  flag=0;
  if(digitalRead(inPin)==HIGH && count_enable==0) {
    Serial.println("reached");
    myTimer.begin(inter_routine, 150000);
    count_enable=1;
  }
  if(flag==1) {
    Serial.println(count);
    //myTimer.end();
    flag=0;
    //count_enable=0;
    count=0;
    digitalWrite(ledPin, HIGH);
  }
  if(count_enable==1) {
    if(count==10)
      count=0;
    count=count+1;
  
 
   //Serial.println(digitalRead(inPin));
  }
  
  
}
