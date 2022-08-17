# Teknostart 2022

I denne teknostarten skal dere i en gruppe lage en fjernstyrt bil og en AI-bildegjenkjenningsmodul. Dere skal få jobbe med Raspberry Pi, Arduino Uno og LOBE. Det er ikke forventet at du skal kunne noe om dette fra før av eller vite hva det er, teknostart vil fungere som en introduksjon til dette, som dere vil få god bruk for senere.  Dere skal også bygge bilen, koble den opp få alt til å fungere sammen. 
Hovedkonkurransen er TBA. Det er også poeng for estetikk, så bruk kreativiteten, maling og tusjer til å lage bilen som dere ønsker. 
Dere bør dele dere opp og jobbe på hver deres del. En viktig del av teknostart er å samarbeide godt og fordele arbeidsoppgaver. Dette er ulike deler dere kan jobbe på. Vi foreslår at dere fordeler dere på disse hovedoppgavene:
1.	Den som ønsker en utfordring, kan jobbe med Raspberry Pien. Her er det viktig å holde tungen beint i bunnen og følge oppskriften til punkt og prikke for at ting skal fungere. Får dere problemer her, ta kontakt med en student assistent. 
2.	Dere får også muligheten til å lage en egen bildegjenkjenningsmodul med LOBE. VI har også laget en modul dere kan bruke, men vi oppfordrer dere til å lage en egen om dere får tid. 
3.	En annen oppgave er å sette opp Arduinoen med motorskiven, og laste opp den ferdigskrevne koden. 
4.	Til slutt kan dere alle samarbeide om å koble alt sammen og få bilen til å fungere sammen. Vent på en studass før dere får batteriet og får startet bilen. 
5.	Når dere ikke har noe å gjøre, bruk tiden til å pynt bilen med maling og tusjer. 


# Table of Contents
- [Teknostart 2022](#teknostart-2022)
- [Table of Contents](#table-of-contents)
  - [Teknobilen](#teknobilen)
    - [Sette sammen bilen](#sette-sammen-bilen)
  - [Raspberry Pi](#raspberry-pi)
    - [Sette opp SD-kortet](#sette-opp-sd-kortet)
    - [Sette opp Raspberry Pi headless](#sette-opp-raspberry-pi-headless)
      - [SSH inn til Raspberry Pi](#ssh-inn-til-raspberry-pi)
      - [Sette opp Eduroam på Raspberry Pi](#sette-opp-eduroam-på-raspberry-pi)
      - [Få inn riktig programvare](#få-inn-riktig-programvare)
  - [Arduino](#arduino)
    - [Skaff Arduino Software til egen PC](#skaff-arduino-software-til-egen-pc)
    - [Last inn koden til Arduinoen](#last-inn-koden-til-arduinoen)
  - [(Bonus) Lobe](#bonus-lobe)
    - [Lag deres egen modell med maskinlæring](#lag-deres-egen-modell-med-maskinlæring)

## Teknobilen

### Sette sammen bilen
Kun veiledende instruks/rekkefølge. Lov å gjøre en annen rekkefølge.
1.	Fest motorer til sidevegger med lange M3 skruer og muttere. 
  * NB! Pass på at de bakre veggene passer når dere setter dem sammen.

<img src="Media/teknobil/01.jpg" height=350>
<img src="Media/teknobil/02.jpg" height=350>
<img src="Media/teknobil/03.jpg" height=350>
<img src="Media/teknobil/04.jpg" height=350>
<img src="Media/teknobil/05.jpg" height=350>

2.	Fest lange standoffs til i bunnplaten med mellomlange M2,5 skruer, 4 til arduinoen og 3 til Raspberry Pi, og korte standoffs til taket med M3. 
    * NB! Merk at det ene hullet ikke skal brukes, det skal kun være 7 standoffs totalt følg bildet.

<img src="Media/teknobil/06.jpg" height=350>
<img src="Media/teknobil/07.jpg" height=350>

Tips: Det kan være lurte å holde platen opp ned mens du skrur på standoffs

<img src="Media/teknobil/09.jpg" height=350>
<img src="Media/teknobil/15.jpg" height=350>

3.	Skru arduino fast til bakerste standoffs i bunnen med korteste M2, og DC-DC converter til taket på korte svarte standoffs med M3.

<img src="Media/teknobil/10.jpg" height=350>
<img src="Media/teknobil/16.jpg" height=350>

4.	Sett sidestøttene ned i bunnplaten, og tre veggene på.

<img src="Media/teknobil/11.jpg" height=350>
<img src="Media/teknobil/12.jpg" height=350>

5.	Skru kamera fast i frontveggen, og sett inn to gule LEDs, samt to røde LEDs i bakveggen, og tre både frontveggen og bakveggen også på.

<img src="Media/teknobil/13.jpg" height=350>

6.	Sett på hjul.
7.	Koble motorene til motordriveren, og skru dem fast i gates, som følgende (illustrasjon av hjulene på bilen)

<img src="Media/teknobil/14.jpg" height=350>
<img src="Media/teknobil/motor.png" height=300>

* NB: Rød ledning er +, og svart er –
SJEKK OVERSIKT PÅ CONVERTER HVILKE PINS/U SOM ER + (Vout) OG – (GND)
8.	Koble USB-port til DC-DC converter i port 3 og 4, og batterikabel til GND og Vin.

<img src="Media/teknobil/17.jpg" height=350>
<img src="Media/teknobil/18.jpg" height=350>
<img src="Media/teknobil/19.jpg" height=350>

9.	Bruk tynne kabler til å koble OVin og GND på arduinoen til port 5 og 6, og fra +/- gaten på motordriveren (der det står PWR) til port 7 og 8 på converteren. 

<img src="Media/teknobil/21.jpg" height=350>
<img src="Media/teknobil/22.jpg" height=350>


10.	
Fortsett når SD-kortet er skrevet og satt tilbake inn i Raspberry Pi (heretter RPi)

11.	Skru RPi til fremre standoffs med korte M2,5 skruer, og gjør følgende koblinger mellom RPi og arduino:

 <img src="Media/teknobil/21.jpg" height=350>
<img src="Media/teknobil/22.jpg" height=350>

| Arduino | Raspberry Pi |
|---------|--------------|
| A5      | GPIO 6       |
| A4      | GPIO 13      |
| A3      | GPIO 19      |
| A2      | GPIO 26      |
| GND     | GND          |

<img src="Media/teknobil/Pinout-UNOrev3_latest.png" height=300>
<img src="Media/teknobil/rp2_pinout.png" height=300>

12.	Koble kameraet til RPi med flatkabel. NB: Sørg for at du setter den inn riktig vei!
13.	Sørg for at denne spaken står på 5V

<img src="Media/teknobil/19.1.jpg" height=350>

Når alt over er gjort, tilkall en studass. Vi kommer og sjekker at all oppkobling er riktig, så skal dere få batteriet.

14.	Legg batteriet inn i bilen under arduinoen.
    



16.	Koble frontlys og baklys med breadboard som vist under.


<img src="Media/teknobil/30.jpg" height=300>
<img src="Media/teknobil/24.jpg" height=350>

15.	Fest breadboardet inntil batteriet midt i bilen.

<img src="Media/teknobil/25.jpg" height=350>
<img src="Media/teknobil/26.jpg" height=350>
<img src="Media/teknobil/27.jpg" height=350>
<img src="Media/teknobil/28.jpg" height=350>

18.	Sett på taket og koble RPi til USB-kabel

<img src="Media/teknobil/29.jpg" height=350>

19.	Koble til batteriet


## Raspberry Pi

Raspberry Pi er en lavkostnads, kredittkort-størrelse datamaskin, der alt du trenger for å bruke som en hvilken som helst annen PC en monitor/TV, et tastatur, og en mus. Den klarer alt som er å forvente av en PC, i alt fra websurfing til å spille av høydefinerte videoer, spill og mye mer.
Videre, kan Raspberry Pi muligheten til å samhandle med resten av verden, og har blitt brukt til en rekke digitale skaper-prosjekter. Disse prosjektene tar på alt fra musikkskaping og værstasjoner til selvkjørende droner og fuglehus som poster på Instagram.
I dette prosjektet brukes modellen Raspberry Pi 3B+. Den brukes til å lage en webserver som streamer live-video fra et Raspberry kamera, hvor du, mens du er i nettleseren, kan bruke piltastene til å styre bilen. Dette gjøres ved at du sender informasjon om tastetrykk til RPi-en, og denne sender videre informasjon til arduinoen, som er et mikrokontrollerkort. I dagligtale er det, i et slikt prosjekt, vanlig å kalle Pien for hjernen, som bruker arduino som slave.
Som alle andre datamaskiner har denne også et operasjonssystem, eller OS. Raspberry Pi sitt OS ligger på et SD-kort, som er mulig å ta ut og inn. Dette SD-kortet fungerer også som maskinens harddrive. Derfor er det naturlig at prosessen med å klargjøre Raspberry Pi-en starter i å sette opp SD-kortet.

### Sette opp SD-kortet

Utstyr:

- Laptop
- SD-kort
- SD-kortleser

SD-kortene dere har fått utdelt inneholder ingen informasjon dere kan bruke. Derfor må dere starte med å laste opp en OS til dette kortet. RPi bruker ikke Windows eller MacOS, men et operativsystem som ofte kalles Rasbian/Debian, som er en versjon av Linux. For å kunne laste opp dette OS-et til kortet kreves et eget skrivebordsprogram som heter Raspberry Pi Imager.

Slik går du fram for å sette opp SD-kortet:

1. Last ned Raspberry Pi Imager
2. Sett inn SD-kortet inn i SD-kortleseren
3. Åpne Raspberry Pi Imager
4. Trykk på «CHOOSE OS» og velg: «Raspberry Pi OS (32-bit)»
5. Videre «CHOOSE STORAGE», og velg det SD-kortet du satte inn.
6. Gå inn på settings:

   ![Raspberry Pi Imager](Media/rpi/01Pi-imager.png)

   1. Sett hostname til «ELSYS"gruppenummer"», eksempel: ELSYS14
   2. Enable SSH
      - Use password authentication
   3. Set username and password
      - Username: teknostart NB! viktig at dere kun skriver “teknostart”
      - Password: "123", eller noe annet dere lett kan huske
   4. Enable Set locale settings:
      - Time zone: Europe/Oslo
      - Keyboard layout: no
   5. Når du er ferdig skal det se noe tilsvarende:

   ![Raspberry Pi Imager settings](Media/rpi/02settings.png)

7. Lagre innstillingene, og trykk på write, dette kan ta litt tid.
8. Når SD-kortet er ferdig skrevet vil du få en beskjed om at det er trygt å ta det ut av maskinen. Ta det ut, og sett inn i Pi-en.


### Sette opp Raspberry Pi headless
Som sagt er Raspberry Pi en datamaskin, men som du kanskje ser er det ikke akkurat en laptop. Det fine med Raspberry Pi er at den kan settes opp og styres headless, altså at man verken trenger et eksternt monitor eller tastatur. For å bruke den headless tar vi i bruk Secure Shell Protocol eller også kjent som SSH, som du aktiverte i “Advanced options”.

Utstyr:
- Laptop
- Ethernet kabel
- Ethernet inngang (adapter hvis laptopen ikke har en dedikert inngang spør en studass ved behov)
- Raspberry Pi med ferdig installert SD-kort

#### SSH inn til Raspberry Pi

1. For å koble deg til Pi-en kobler du Raspberry Pi til laptopen via ethernet kabelen og ved behov en ethernet adapter.
2. Åpne en terminal på laptopen:
   - For Windows kan dere søke opp:
     - Terminal (🪟 + x)
     - Windows PowerShell
     - Command Promt
   - For Mac kan dere søke opp:
     - Terminal
3. For å SSH inn til Pi-en går du inn på terminalen og skriver (du kan også copypaste ved kopiere vanlig for så å lime inn med høyre klikk inne på terminalen.):
   ```bash
   ssh teknostart@<hostname>.local
   ```
   - Som du satte i Raspberry Pi imager F.eks:
     ```bash 
     teknostart@ELSYS1.local 
     ```
     -NB! Det kan ta litt tid før Pi-en skrur seg på, så om den ikke finner Pi-en med en gang så bare vent noen minutter og prøv igjen.
     _ Når den spør om du ønsker å koble deg til skriver du “yes” og trykker enter.
     _ Du vil få noe tilsvarende:
     ![SSH into Raspberry Pi](Media/rpi/03SSH.png)
Gratulerer du har nå SSH-et inn til deres Raspberry Pi. Kommandoene du nå skriver skjer inne på selve Raspberry Pi.

#### Sette opp Eduroam på Raspberry Pi

1. Først må du sette opp WLAN country for å kunne koble deg på nett og samtidig aktivere kameraet. Bruk kommandoen:

```bash
sudo raspi-config
```

- Gå videre inn på “Localisation options” -> “WLAN Country”, scroll ned til du finner “Norway” og trykk enter.
- Gå inn på “Interface options” -> “Legacy Camera” og enable.
- Naviger til <Finish> ved å trykke “høyre piltast” og trykk enter. Pi-en vil nå starte på nytt. Vent noen minutter og SSH inn igjen.

2. Gå nå inn på superuser mode. Dette gjøres ved å bruke kommandoen:

```bash
sudo su
```

3. Deaktiver WLAN med kommandoen:

```bash
ifconfig wlan0 down
```

4. Deretter avslutter du alle prosesser assosiert med wpa_supplicant med kommandoen:

```bash
killall wpa_supplicant
```

5. Nå som wpa er deaktivert kan kan du modifisere på konfigurasjonsfilene. Dette gjøres med kommandoen:

```bash
nano /etc/network/interfaces
```

- Erstatt innholdet i tekstfilen med:

```bash
source-directory /etc/network/interfaces.d/*

allow-hotplug wlan0
iface wlan0 inet manual
	wpa-conf /etc/wpa_supplicant/wpa_supplicant.conf

iface wlan0 inet dhcp
```
![Interface](Media/rpi/04interface.png)

6. Lagre og gå ut:
   - trykk ctrl+x, så “y”, og enter.
7. Nå kan vi endre på på wpa_supplicant, slik at den får informasjonen den trenger til å koble seg på “Eduroam”. Gå inn på:

```bash
nano /etc/wpa_supplicant/wpa_supplicant.conf
```

* Erstatt innholdet i tekstfilen med:

```bash
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1
country=NO

network={
	ssid="eduroam"
	eap=PEAP
	key_mgmt=WPA-EAP
	phase2="auth=MSCHAPV2"
	identity="elsys_teknostart@ntnu.no"
	password="M97U@snq25"
}
```
![wpa_suplicant](Media/rpi/05wpa_supplicant.png)
8. Lagre og gå ut:
   - trykk ctrl+x, så “y”, og enter.
9. For å teste om innstillingene fungerer kan du test koblingen med kommandoen:

```bash
wpa_supplicant -i wlan0 -c /etc/wpa_supplicant/wpa_supplicant.conf
```

- Du vil da få en linje som sier “EAP-MSCHAPV2: Authentication succeeded” og se noe tilsvarende:
![test1](Media/rpi/06test.png)
- Den vil etter dette henge seg opp. For å gå ut av testen trykker du ctrl+c for å tvinge avslutning av testen.

10. Du kan nå aktivere WLAN igjen med kommandoen:

```bash
ifconfig wlan0 up
```

11. Start Raspberry Pi igjen med kommandoen:

```bash
reboot
```

12. SSH inn til Raspberry Pien igjen og test koblingen med kommandoene:

```bash
iwconfig
ping -c 3 www.google.com
```

    * Du vil få noe tilsvarende:
![Test2](Media/rpi/07test2.png)
Gratulerer, du har nå satt opp eduroam nettet på Raspberry Pi.

#### Få inn riktig programvare

Vi skal nå få inn riktig programvare, samt laste inn alt av kode som skal ligge lokalt på Pien.

1. Start med å sjette at klokken inne på Raspberry Pien stemmer med kommandoen:

```bash
date
```
![Date](Media/rpi/08check_date.png)
    * Dersom dato og klokken er feil kan du fikse opp i dette ved å bruke kommandoen (Husk å endre dato/klokkeslett til gjeldende tid):

```bash
sudo date -s '18 Aug 2022 13:00'
```
![Change](Media/rpi/09change_date.png)
2. Nå kan du oppdatere og oppgradere med kommandoene

```bash
sudo apt-get update
sudo apt-get dist-upgrade
```

- Trykk enter når dem spør om du ønsker å fortsette.


3. Nå kan du klone git-en som inneholder koden som Raspberry Pi-en skal kjøre med kommandoen:

```bash
git clone https://gitlab.stud.idi.ntnu.no/ELSYS_teknostart/teknobil2022.git
```
    *NB dette kan ta litt tid
4. Videre kan du navigere deg inn på "teknobil2022" mappen med kommandoen:
   
```bash 
cd teknobil2022/
```

5. Last ned ekstra progrmvare som kreves for å kjøre koden med kommandoen:
```bash
pip3 install -r requirements.txt
sudo apt-get install libatlas-base-dev
sudo apt-get install python3-pyro4
```
6. Naviger videre inn i "projectfolder" med kommandoen:

```bash
cd projectfolder/
```
7. Når Arduino koden er ferdig lastet kan du kjøre Python koden med kommandoen:

```python
python runCode.py
```

## Arduino
Arduino er en open-source elektronikkplattform basert på hardware og software designet for å være enkelt å bruke. Arduinokortene er rusta til å lese ulike inputs - lys på en sensor, knappetrykk, en Twittermelding – og bruke denne dataen til å sende et outputsignal – aktivere en motor, skru på en LED, publisere noe på nett. Du kan fortelle kortet hva den skal gjøre, ved å sende opp sett med instruksjoner til mikrokontrolleren på kortet i form av kodesnutter i programmeringsspråket C. Disse instruksjonene sendes til kortet via en USB-kabel fra din PC, men for at denne informasjonen skal lastes opp riktig må vi ha koden vår i en Arduino Software (IDE).

### Skaff Arduino Software til egen PC

Last ned Arduino IDE
* [Windows](https://docs.arduino.cc/software/ide-v1/tutorials/Windows#download-the-arduino-software-ide)
* [MacOS](https://docs.arduino.cc/software/ide-v1/tutorials/macOS?_gl=1*17wzpvg*_ga*MTY2NjU1MjEzOC4xNjI5OTYzMDk1*_ga_NEXN8H46L5*MTY1NTIwNjQyMy4zMy4xLjE2NTUyMDk1MTcuNjA.)
* [Linux](https://docs.arduino.cc/software/ide-v1/tutorials/Linux?_gl=1*xpugwf*_ga*MTY2NjU1MjEzOC4xNjI5OTYzMDk1*_ga_NEXN8H46L5*MTY1NTIwNjQyMy4zMy4xLjE2NTUyMDk1NDcuMzA.)

### Last inn koden til Arduinoen
Utstyr:
1. Laptop
2. Usb-A til usb-b kabel
3. Arduino Uno

Oppsett:
1. Koble til arduino-kortet til din PC med en USB-B ledningen
2. Sørg for at softwaren fungerer for riktig type arduinokort, her Arduino Uno
    * Gå inn på «Verktøy»/«Tools»
    * Velg riktig kort og port (porten er hvilken inngang/utgang du bruker på PC-en. Kan komme feilmelding om det velges feil)

![Arduino](Media/arduino/01toolssetup.png)

3. Videre erstatter du teksten med koden under:
    <details>
    <summary>Klikk her</summary>

    ```c
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
    ```
    </details>

4. Last opp koden til arduinokortet. Blå først for å verifisere koden (dobbeltsjekke at det ikke er noen feil med koden). Deretter rød for å laste opp.

<img src="Media/arduino/02yeah.png" width="240">

NB: Om motoren skulle gått i feil retning når dere tester full oppkobling, er det trolig noe feil i oppkoblingen (enten feil motor til feil port, eller feil på +/- på motordriverens innganger). Dette kan dere prøve å endre på selv i arduino-koden under «MOTOR SETUP», for å slippe å gjøre omkoblinger, og for en liten ekstra utfordring:)

## (Bonus) Lobe

### Lag deres egen modell med maskinlæring
Det vi kaller object detection, eller objekt gjenkjenning, er en teknikk en datamaskin tar i bruk for å lokalisere objekter i bilder eller videoer. Vi mennesker kjenner fort igjen ulike objekter i bilder og videoer, og skille dem, ila. millisekunder. Målet med object detection er å kunne gjenskape denne egenskapen i en datamaskin. For å få til dette er det ofte tatt i bruk machine learning, som går ut på at maskinen lærer opp seg selv. 
For å slippe å skrive egen kode for dette skal vi benytte et open-source program kalt LOBE. I dette programmet kan en legge inn bilder av de objektene man ønsker at maskinen/programmet skal kunne kjenne igjen, og sette merkelapp på dem. Disse bildene vil så LOBE bruke til å trene opp en modell (type program), til den klarer å kjenne igjen alle objektene den har merkelapp til. Denne modellen, i form av en mappe, legger vi inn på vår RPi, og du vil ha en egenlaget og fungerende gjenkjenningsmodell når du kjører bilen!


####	Last ned LOBE
-	Trykk på Download på denne nettsiden

Bildene som skal brukes til å lage denne modellen skal tas med RPi, og for å få lagret disse lokalt på PC-en skal vi benytte en ny programvare
#### Last ned riktig programvare for å kunne ta bilder med RPi
-	git clone https://github.com/silvanmelchior/RPi_Cam_Web_Interface.git
-	cd RPi_Cam_Web_Interface
-	./install.sh
Under nedlastingen vil du få opp denne menyen:
 <img src="Media/Lobe/01.jpg" height=350>

Sørg for at alle parametere er like som på bildet over!

#### Ta bilder
1.	Start programvaren med å skrive kommandoen /.start.sh i terminalen
2.	Åpne en ny fane i nettleseren og bruk RPi-en sin IP-adresse som nettstedssøk
Hvis du ikke vet IP-adressen fra før kan du finne den med kommando ifconfig

<img src="Media/Lobe/02.jpg" height=300>

På plassen markert i rødt vil IP-adressen stå

3.	Når du kommer inn på nettsiden følger du linken html. Da burde du komme hit:
<img src="Media/Lobe/03.jpg" height=350> 

Om bildet er opp ned kan du gå inn på Camera Settings og sette flip-instillingen til Vertical

4.	Trykk på record image for å ta bilder. Tips for best mulig gjenkjenningsmodell:
-	Ta mange bilder av hvert objekt
-	Helst fra ulike vinkler
-	Kan vurdere ulike bakgrunner/underlag

5.	For å få lastet ned, trykk på Download Videos ond Images  Select All  Get Zip
Denne vil bli lastet ned lokalt på egen PC, velg en filplassering du husker.

#### Lag gjenkjenningsmodell
1.	Åpne Lobe
2.	Velg New Project
3.	Inne på Label (i sidemenyen), trykk på Import
-	Her skal du velge de bildene du tok i forrige steg
Tips når du skal sette label (to alternativer):
a)	Last opp bildene til ett objekt om gangen, da kan du markere alle bildene med Ctrl+A, og skrive label for alle bildene samtidig. Dette gjøres ved Import -> Images

b)	Legg alle bildene av samme objekt i en egen mappe, der mappenavnet er labelen til objektet. Sett deretter alle objekt-mappene i en felles mappe. Last opp ved å trykke på Import -> Dataset. Eksempel:


<img src="Media/Lobe/04.jpg" height=150>

4.	Når alle bildene har fått label, gå inn på Train, og vent til denne har kommet til 100%

<img src="Media/Lobe/05.jpg" height=100>

####   Bruk modellen
1.	Gå inn på Use, deretter trykk på export
2.	Velg alternativet TensorFlow Lite, dette vil gi deg en mappe som brukes i koden for RPi-en, derfor er det viktig å gi denne mappen navnet «Lobe», og plassere denne et sted du husker!
3.	For å få denne inn i mappestrukturen til RPi-en deres så modellen deres faktisk blir brukt, må den erstatte den modellen som allerede ligger inne. Derfor er det nødvendig å laste ned et skrivebordsprogram som lar deg overføre filer og mapper mellom to maskiner, her egen PC og RPi

    Windows:
    1.	Last ned WinSCP
    2.	Når nedlastningen er ferdig, åpne programmet
    3.	Skriv inn Vertsnavn (Hostname), brukernavn og passord til RPi-en deres for å få en tilkobling. Det vil da komme opp mappestrukturen til RPi-en på venstre side av programvinduet
    4.	Erstatt Lobe-mappen som ligger på RPi-en fra før, med den du nettopp har laget

    MacOs
    1.	Last ned FileZilla
    2.	Åpne programmet når nedlastningen er ferdig
    3.	Fyll inn Vert (Hostname), brukernavn og passordet til RPi-en deres for å få en tilkobling. Det vil da komme opp mappestrukturen til RPi-en på venstre side av programvinduet
    4.	Erstatt Lobe-mappen som ligger

Når du kjører «runCode.py» fra RPi-en nå, vil den ta i bruk deres egen object detection!!! 
