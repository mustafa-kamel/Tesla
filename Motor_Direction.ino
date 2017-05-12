#define right    8
#define left     9

char command;
String string;

void setup(){
  Serial.begin(9600);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
}


void loop(){

  if (Serial.available() > 0)
    string = "";
    
  while(Serial.available() > 0){
    command = ((byte)Serial.read());
    if(command == ':')
      break;
    else
      string += command;
      
    delay(1);
  }

  Serial.print(""+string);
  if(string == "right")
    turnOn(right);          
  else if(string == "left")
    turnOn(left);
  else if(string == "Stop")
    Stop();
}
                                /////////
void turnOn(int dir){
  Stop();
  digitalWrite(dir, HIGH);
  delay(100);
}
 
void Stop(){
  digitalWrite(right, LOW);
  digitalWrite(left, LOW);
  delay(100);
}   
