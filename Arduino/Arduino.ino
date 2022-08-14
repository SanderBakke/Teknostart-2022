//MOTOR SETUP
const int E1 = 3; ///<Motor1 Speed - Front Right
const int E2 = 11;///<Motor2 Speed - Front Left
const int E3 = 5; ///<Motor3 Speed - Back Right
const int E4 = 6; ///<Motor4 Speed - Back Left

const int M1 = 4; ///<Motor1 Direction - Front Right
const int M2 = 12;///<Motor2 Direction - Front Left
const int M3 = 8; ///<Motor3 Direction - Back Right
const int M4 = 7; ///<Motor4 Direction - Back Left


/////////LOGIC/////////////////////////////////
//INPUT PINS
int drive = A5;
int reverse = A4;
int leftTurn = A3;
int rightTurn = A2;

//BOOLS
int go = 0;
int back = 0;
int left = 0;
int right = 0;


//SPEEDS
int drivingSpeed = 150;
int turningSpeed = 50;


//////DRIVING FUNCTIONS//////////////////////
void speedSet(String motors, int Speed){
  //Choose speed from 0-255
  if(motors == "right"){
    analogWrite(E1, Speed);
    analogWrite(E3, Speed);
    }
  else if(motors == "left"){
    analogWrite(E2, Speed);
    analogWrite(E4, Speed);
  }
  else if(motors = "both"){
    analogWrite(E1, Speed);
    analogWrite(E2, Speed);
    analogWrite(E3, Speed);
    analogWrite(E4, Speed);
  }
}

//DRIVING FUNCTION
void driving(String motors, bool Direction){
  //Direction = 0 -> forward
  //Dircetion = 1 -> reverse
  if (motors == "both"){
  digitalWrite(M1, Direction);
  digitalWrite(M2, Direction);
  digitalWrite(M3, Direction);
  digitalWrite(M4, Direction);
  }
  else if (motors = "right"){
    digitalWrite(M1, Direction);
    digitalWrite(M3, Direction);
  }
  else if (motors = "left"){
    digitalWrite(M2, Direction);
    digitalWrite(M4, Direction);
  }
}


////SETUP///////////////////////
void setup() {
  Serial.begin(9600);   
  Serial.println("Starting session...");

  //SET PINS 
  pinMode(drive,INPUT);
  pinMode(reverse, INPUT);
  pinMode(leftTurn, INPUT);
  pinMode(rightTurn, INPUT);
  for(int i=3;i<9;i++)
    pinMode(i,OUTPUT);
  for(int i=11;i<13;i++)
    pinMode(i,OUTPUT);
    
}

void loop() {
//UPDTAING THE BOOLEANS
  go = digitalRead(drive);
  back = digitalRead(reverse);
  left = digitalRead(leftTurn);
  right = digitalRead(rightTurn);

  
/////FORWARD DRIVE/////////////////////////////////////////
  if(go && !back){  
    driving("both", 0);  
    //FORWARD WITH A RIGHT TURN
    if(right){
      speedSet("right",turningSpeed);
    }
    //FORWARD WITH A LEFT TURN
    else if(left){
      speedSet("left",turningSpeed);
    }
    else{
      speedSet("both", drivingSpeed);
      Serial.println("FORWARD");
    }
  }

  
  //REVERSE
  else if(back && !go){
    driving("both", 1);
    //REVERSE WITH RIGHTTURN
    if(right){
      speedSet("right",turningSpeed);
    }
    //REVERSE WITH LEFTTURN
    else if(left){
      speedSet("left", turningSpeed);
    }
    else{
      speedSet("both", drivingSpeed);      
      Serial.println("REVERSE");
    }
  }



 //RIGHTTURN
  else if(right && !go && !back){
    speedSet("both", turningSpeed);
    if(!left){
      digitalWrite(M1,1);
      digitalWrite(M3,1);
      digitalWrite(M2,0);
      digitalWrite(M4,0);
      //driving("left", 0);
      Serial.println("RIGHTTURN");
    }
    
    //IF YOU PRESS BOTH LEFT AND RIGHT
    else{
      driving("both", 0);
    }
  }

  //LEFTTURN
  else if(left && !go && !back){
    speedSet("both", turningSpeed);
    if(!right){
      digitalWrite(M1,0);
      digitalWrite(M3,0);
      digitalWrite(M2,1);
      digitalWrite(M4,1);
      //driving("right",0);
      //driving("left", 1 );
      Serial.println("LEFTTURN");
    }
  
  //IF YOU PRESS BOTH LEFT AND RIGHT
    else{
      driving("both", 0);
    }
  }

  //IF YOU DON'T PRESS ANYTHNIG
  else{
    speedSet("both", 0);
    Serial.println("STOP");
 }
}
