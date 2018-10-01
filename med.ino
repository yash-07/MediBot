  #include <ESP8266WiFi.h>
  #include <FirebaseArduino.h>
  #define FIREBASE_HOST "medibot-zee.firebaseio.com"
  #define FIREBASE_AUTH "2cz4ULcXT11CXWt4SEinO3N5rrK03q5h5BmsmOIC"
  
  #define WIFI_SSID "Sidhu vinu"
  #define WIFI_PASSWORD "Parmar@65"
  /*
  #define M1 D0
  #define M2 D1
  
  #define M3 D2
  #define M4 D3
*/  
  
//  int servoPin = D6; 
  String a,pathx;
  int temp,Var,person,tm;
//Default Setup
  void setup() {
      pinMode(D0,OUTPUT);
      pinMode(D1,OUTPUT);
      pinMode(D2,OUTPUT);
      pinMode(D3,OUTPUT);
      pinMode(D4,OUTPUT);
      pinMode(D5,OUTPUT);
   
   
    Serial.begin(9600);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("connecting");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
    Serial.println("Connected!!");
    Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  }
  
  void loop() {
    temp=1;

    Var=Firebase.getInt("/sys/Var");
    person=Firebase.getInt("/person");
    tm=Firebase.getInt("/time");
    if(temp == 1 && person!=0 && person>0 && person<=4)
    {
       temp=0;
       String path = "/sys/Var/";
       pathx = path + person;
       path = pathx + "/";
       path = path + tm;
       Serial.println(path);
       String pathA = path       +  "/a";
       a=Firebase.getString(pathA);
       Serial.println(person); 
       Serial.println(tm);
       Serial.println(a);
      String x=a;
       Serial.println(a);
       
      // digitalWrite(x,HIGH);
        delay(2000);
       Firebase.setInt("/person",0);
       Firebase.setInt("/time",0);
       
  }
 
  }
