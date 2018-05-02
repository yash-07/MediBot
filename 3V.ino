    #include <ESP8266WiFi.h>
    #include <FirebaseArduino.h>
    #include <Servo.h>
    // Set these to run example.
    
    #define FIREBASE_HOST "test-1b6b7.firebaseio.com"
    #define FIREBASE_AUTH "7zVayxDV3ljh9Xg6zK6iIitZy9985hgc2KNmTENg"
    
    #define WIFI_SSID "VJ"
    #define WIFI_PASSWORD "12345678"
    
    #define M1 D0
    
    #define M2 D1
    
    #define M3 D2
    #define M4 D4
    
    #define buzz D5
    //const byte ledPin = 13;
//int pin = D3;
volatile byte state = HIGH;

    int servoPin = D6,one,two,three,four;
    int r1, r2, r3, a, sel,i;
    String path1,path2,path3,path4;
    // Create a servo object
    Servo spiral;
    void setup() {
        pinMode(D3,INPUT); //set pin 13 as output
  // attachInterrupt(digitalPinToInterrupt(pin), stop, CHANGE);
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);
    pinMode(D8, OUTPUT);
     
      pinMode(D0, OUTPUT);
      pinMode(D1, OUTPUT);
      pinMode(D2, OUTPUT);
      pinMode(D4, OUTPUT);
      pinMode(D5, OUTPUT);
      spiral.attach(servoPin);
      //  Servo1.attach(servoPin);
      Serial.begin(9600);
      WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
      Serial.print("connecting");
      while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
      }
      Serial.println("Connected!!");
      Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
      int a=Firebase.getInt("");
    }
    
    
    void loop() {
     
       
      if (Firebase.getInt("/move") == 1) {
    
        if (Firebase.getInt("/select") == 0) {
    
          a = Firebase.getInt("/dists/a");
          frwd();
          delay(a * 1000);
          low();
    
          r1 = Firebase.getInt("/dists/r1");
          left();
          delay(1500);
          low();
    
          frwd();
          delay(r1 * 500);
          left();
          delay(600);
          frwd();
          delay(r1 * 500);  
          low();
  st();
    stop();
          buzzer();
    name();
          left();
          delay(6000);
          low();
    
          frwd();
          delay(r1 * 500);
          left();
          delay(600);
          frwd();
          delay(r1 * 500);  
          
          //
    
          r2 = Firebase.getInt("/dists/r2");
          left();
          delay(1500);
          low();
  st();  
          frwd();
          delay(r2 * 500);
          left();
          delay(600);
          frwd();
          delay(r2 * 500);  
          stop();
          buzzer();
    name();
          left();
          delay(4200);
          low();
          frwd();
       st();
          delay(r2 * 500);
          left();
          delay(600);
          frwd();
          delay(r2 * 500);  
          
          //
    st();
          r3 = Firebase.getInt("/dists/r3");
          left();
          delay(1500);
          low();
    frwd();
          delay(r3 * 500);
          left();
          delay(600);
          frwd();
          delay(r3 * 500);  
         st(); 
    stop();
          buzzer();
    name();
          left();
          delay(4200);
          low();
    frwd();
          delay(r3 * 500);
          left();
          delay(600);
          frwd();
          delay(r3 * 500);  
          st();
          //
    
          left();
          delay(1500);
          low();
    
          frwd();
          delay(a * 1000);
          low();
    st();
          left();
          delay(4200);
          low();
        Firebase.setInt("/move",0);
        } else {
    
          sel = Firebase.getInt("/select");
          if (sel == 1) {
    st();
            a = Firebase.getInt("/dists/a");
            frwd();
            delay(a * 1000);
            low();
    stop();
            r1 = Firebase.getInt("/dists/r1");
            left();
            delay(1500);
            low();
    frwd();
          delay(r1 * 500);
          left();
          delay(600);
          frwd();
          delay(r1 * 500);  
          
    
            buzzer();
    name();
            left();
            delay(4000);
            low();
    st();
          frwd();
          delay(r1 * 500);
          left();
          delay(600);
          frwd();
          delay(r1 * 500);  
            ///
    
            right();
            delay(1500);
            low();
    
            frwd();
            delay(a * 1000);
            low();
    
            right();
            delay(4000);
            low();
    st();
          stop();
          }
          else if (sel == 2) {
            a = Firebase.getInt("/dists/a");
            r2 = Firebase.getInt("/dists/r2");
            frwd();
            delay((a + r2) * 1000);
            low();
    
            buzzer();
    name();
            right();
            delay(4000);
            frwd();
            delay((a + r2) * 1000);
         st();
         low();
    
            right();
            delay(4000);
            low();
    
          }
          else if (sel == 3) {
    st();
            a = Firebase.getInt("/dists/a");
            frwd();
            delay(a * 1000);
            low();
    
            r3 = Firebase.getInt("/dists/r3");
            right();
            delay(1500);
            low();
    
          frwd();
          delay(r3 * 500);
          left();
          delay(600);
          frwd();
          delay(r3 * 500);  
          stop();
            buzzer();
    name();
    st();
            right();
            delay(4000);
        low();
frwd();
      delay(r3 * 500);
      left();
      delay(600);
      frwd();
      delay(r3 * 500);  
      
        left();
        delay(1500);
        low();
frwd();
st();
      delay(r3 * 500);
      left();
      delay(600);
      frwd();
      delay(r3 * 500);  
      stop();
        left();
        delay(4000);
        low();
st();
      }
      Firebase.setInt("/select", 0);
    }
    Firebase.setInt("/move", 0);
  }

}

void frwd()
{
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
}
void low ()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);

}
void right() {
  digitalWrite(D4, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D0, HIGH);
  digitalWrite(D1, LOW);
}
void left() {

  digitalWrite(D1, HIGH);
  digitalWrite(D0, LOW);
  digitalWrite(D4, HIGH);
  digitalWrite(D2, LOW);
}

void buzzer() {

  digitalWrite(buzz, HIGH);
  delay(2000);
  digitalWrite(buzz, LOW);

}     
void name()
{ 
  Firebase.setInt("/click",1);
delay(6000);
//if(digitalRead(D5==HIGH)
//delay(1000);  
}
void stop()
{ digitalRead(D3==HIGH);
delay(6000);
  i=Firebase.getInt("/name");
  String path = "/Person/";
  switch(i) {

  case 1: path.concat("vipul");
          break;
  case 2: path.concat("vikram");
          break;
  case 3: path.concat("vedadnya");
          break;
  }
  path.concat("/morning/");
  path1 = path;
  path2 = path;
  path3 = path;
  path4 = path;

  path1.concat("/1/taking");
  path2.concat("/2/taking");
  path3.concat("/3/taking");
  path4.concat("/4/taking");
  
  one = Firebase.getInt(path1);
  two = Firebase.getInt(path2);
  three = Firebase.getInt(path3);
  four = Firebase.getInt(path4);
//  for(i=0;i<4;i++)
if(one==one)
{digitalWrite(D5,HIGH);
}
if(two==two)
{digitalWrite(D6,HIGH);
delay(5000);
digitalWrite(D6,LOW);
}if(three==three)
{digitalWrite(D7,HIGH);
delay(5000);
digitalWrite(D7,LOW);
}if(four==four)
{digitalWrite(D8,HIGH);
delay(5000);
digitalWrite(D8,LOW);
}
}
//    {for(j=0;j<4,j++)
//    {
//  for({
//    path="/Person/";
//     path.concat(i);
//path.concat(j);
//  }
//if(Firebase.getInt("/Person/vedadnya/morning/")




     
  

void st()
{ if(Firebase.getInt("/name")!=0)
  digitalWrite(D1, HIGH);
  digitalWrite(D0, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(D2, HIGH);
}
  
