int pedestrianRed = 1;
int pedestrianGreen = 2;
int trafficGreen = 8;
int trafficYellow = 9;
int trafficRed = 10;
int pushButton = 0;
bool press = false;

void setup()
{
  pinMode(pedestrianRed, OUTPUT);
  pinMode(pedestrianGreen, OUTPUT);
  pinMode(trafficGreen, OUTPUT);
  pinMode(trafficYellow, OUTPUT);
  pinMode(trafficRed, OUTPUT);
  pinMode(pushButton, INPUT);
  
}

void loop()
{
  //green for traffic and red for pedestrian
  //when the button is not pressed
  digitalWrite(trafficGreen, HIGH);
  digitalWrite(pedestrianRed, HIGH);
  
  if(digitalRead(pushButton) == LOW){
    press = true;
    pedestrianCross();
  }
}

void pedestrianCross(){//sequence of the light
  if(press == true);
  delay(5000);//let pedestrian wait for a while
  digitalWrite(trafficGreen, LOW);
  digitalWrite(trafficYellow, HIGH);
  delay(3000);
  digitalWrite(trafficYellow, LOW);
  digitalWrite(trafficRed, HIGH);
  delay(2000);
  digitalWrite(pedestrianRed, LOW);
  digitalWrite(pedestrianGreen, HIGH);
  delay(15000);
  //flashing pedestrianGreen before turn back to red
  for(int i = 0; i < 5; i++){
    digitalWrite(pedestrianGreen, LOW);
    delay(500);
    digitalWrite(pedestrianGreen, HIGH);
    delay(500);
  }
  
  digitalWrite(trafficYellow, HIGH);
  delay(1000);
  digitalWrite(pedestrianGreen, LOW);
  digitalWrite(pedestrianRed, HIGH);
  delay(1000);
  digitalWrite(trafficYellow, LOW);
  digitalWrite(trafficRed, LOW);
  
  
  
  
  press = false;
}