//  RC Oscillator

int x = 0;
int x0 = 512;//this should range from 0 to 1023
int deltax = 20; //this should range from 0 to 512

int outPin = 7;

int n = 0;

void setup() {
  Serial.begin(9600);
  pinMode(outPin, OUTPUT);
  digitalWrite(outPin,LOW);
}

void loop() {
  
  x = analogRead(A0);
  
  if(x < x0 - deltax || x < 10){
     digitalWrite(outPin,HIGH);  
  }
  if(x > x0 + deltax || x > 1013){
     digitalWrite(outPin,LOW);  

     if(n>10){
       Serial.println(n);     
     }
     n = 0;
   }
  n++;
}
