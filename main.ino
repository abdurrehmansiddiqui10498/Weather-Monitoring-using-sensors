#include &quot;DHT.h&quot;
#include &lt;Wire.h&gt;
#include &lt;LiquidCrystal_I2C.h&gt;
#include &lt;ESP8266WiFi.h&gt;
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
int h,l,r;
int t;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  Wire.begin(5,4);
  lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight
  lcd.setCursor(0,0);
  lcd.print(&quot;Weather Monitor&quot;);
  lcd.setCursor(5,1);
  lcd.print(&quot;System&quot;);
  lcd.clear();  

}
void loop() {
  // put your main code here, to run repeatedly:
  //delay(2000);
  h = dht.readHumidity();
  t = dht.readTemperature();
  int r = analogRead(A0);
  bool l = digitalRead(D5);
  r = map(r,1024,0,0,100);
  lcd.setCursor(0,0);
  lcd.print(&quot;T:&quot;);
  lcd.print(t);
  lcd.print(&quot;C&quot;);
  lcd.print(&quot; H:&quot;);
  lcd.print(h);
  lcd.print(&quot;%&quot;);
  Serial.print(&quot;T: &quot;);
  Serial.println(t);
  Serial.print(&quot;H: &quot;);
  Serial.println(h);
 
  lcd.setCursor(0,1);
  lcd.print(&quot;R:&quot;);
  lcd.print(r);
  lcd.print(&quot;%&quot;);
  lcd.print(&quot; L:&quot;);
  if (l == 1) {
    lcd.print(&quot;Night      &quot;);
  }
  else {
    lcd.print(&quot;Day         &quot;);
  }
 
  Serial.print(&quot;Rain: &quot;);
  Serial.println(r);
  Serial.print(&quot;Light: &quot;);
  Serial.println(l);
}
