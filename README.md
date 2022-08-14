# Teknostart 2022

# Table of Contents

- [Teknostart 2022](#teknostart-2022)
- [Table of Contents](#table-of-contents)
  - [Raspberry Pi](#raspberry-pi)
      - [Sette opp SD-kortet](#sette-opp-sd-kortet)
  - [Sette opp Raspberry Pi headless](#sette-opp-raspberry-pi-headless)
      - [SSH inn til Raspberry Pi](#ssh-inn-til-raspberry-pi)
      - [Sette opp Eduroam på Raspberry Pi](#sette-opp-eduroam-på-raspberry-pi)
      - [Få inn riktig programvare](#få-inn-riktig-programvare)

## Raspberry Pi

Raspberry Pi er en lavkostnads, kredittkort-størrelse datamaskin, der alt du trenger for å bruke som en hvilken som helst annen PC en monitor/TV, et tastatur, og en mus. Den klarer alt som er å forvente av en PC, i alt fra websurfing til å spille av høydefinerte videoer, spill og mye mer.
Videre, kan Raspberry Pi muligheten til å samhandle med resten av verden, og har blitt brukt til en rekke digitale skaper-prosjekter. Disse prosjektene tar på alt fra musikkskaping og værstasjoner til selvkjørende droner og fuglehus som poster på Instagram.
I dette prosjektet brukes modellen Raspberry Pi 3B+. Den brukes til å lage en webserver som streamer live-video fra et Raspberry kamera, hvor du, mens du er i nettleseren, kan bruke piltastene til å styre bilen. Dette gjøres ved at du sender informasjon om tastetrykk til RPi-en, og denne sender videre informasjon til arduinoen, som er et mikrokontrollerkort. I dagligtale er det, i et slikt prosjekt, vanlig å kalle Pien for hjernen, som bruker arduino som slave.
Som alle andre datamaskiner har denne også et operasjonssystem, eller OS. Raspberry Pi sitt OS ligger på et SD-kort, som er mulig å ta ut og inn. Dette SD-kortet fungerer også som maskinens harddrive. Derfor er det naturlig at prosessen med å klargjøre Raspberry Pi-en starter i å sette opp SD-kortet.

#### Sette opp SD-kortet

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

   ![Raspberry Pi Imager](media/rpi/01Pi-imager.png)

   1. Sett hostname til «ELSYS<gruppenummer>», eksempel: ELSYS14
   2. Enable SSH
      - Use password authentication
   3. Set username and password
      - Username: teknostart NB! viktig at dere kun skriver “teknostart”
      - Password: teknostart, eller noe annet dere husker
   4. Enable Set locale settings:
      - Time zone: Europe/Oslo
      - Keyboard layout: no
   5. Når du er ferdig skal det se noe tilsvarende:

   ![Raspberry Pi Imager settings](https://gitlab.stud.idi.ntnu.no/ELSYS_teknostart/teknobil2022/-/raw/ae492266c2ce8c84b30e6cf0784621395eb24e53/Media/RPI/02settings.png)

   1. Lagre innstillingene, og trykk på write, dette kan ta litt tid.
   2. Når SD-kortet er ferdig skrevet vil du få en beskjed om at det er trygt å ta det ut av maskinen. Ta det ut, og sett inn i Pi-en

Som sagt er Raspberry Pi en datamaskin, men som du kanskje ser er det ikke akkurat en laptop. Det fine med Raspberry Pi er at den kan settes opp og styres headless, altså at man verken trenger et eksternt monitor eller tastatur. For å bruke den headless tar vi i bruk Secure Shell Protocol eller også kjent som SSH, som du aktiverte i “Advanced options”.

## Sette opp Raspberry Pi headless

Utstyr:

- Laptop
- Ethernet kabel
- Ethernet inngang (adapter hvis laptopen ikke har en dedikert inngang)
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
3. For å SSH inn til Pi-en går du inn på terminalen og skriver:
   ```bash
   ssh teknostart@<hostname>.local
   ```
   - som du satte i Raspberry Pi imager F.eks:
     `bash teknostart@ELSYS1.local `
     -NB! Det kan ta litt tid før Pi-en skrur seg på, så om den ikke finner Pi-en med en gang så bare vent noen minutter og prøv igjen.
     _ Når den spør om du ønsker å koble deg til skriver du “yes” og trykker enter.
     _ Du vil få noe tilsvarende:
     ![SSH into Raspberry Pi](https://gitlab.stud.idi.ntnu.no/ELSYS_teknostart/teknobil2022/-/raw/c26b23f8dc90cb0d7639ec7f3c594cd6f60f7fe1/Media/RPI/03SSH.png)
4. Gratulerer du har nå SSH-et inn til deres Raspberry Pi. Kommandoene du nå skriver skjer inne på selve Raspberry Pi.

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

8. Lagre og gå ut:
   - trykk ctrl+x, så “y”, og enter.
9. For å teste om innstillingene fungerer kan du test koblingen med kommandoen:

```bash
wpa_supplicant -i wlan0 -c /etc/wpa_supplicant/wpa_supplicant.conf
```

- Du vil da få en linje som sier “EAP-MSCHAPV2: Authentication succeeded” og se noe tilsvarende:

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

Gratulerer, du har nå satt opp eduroam nettet på Raspberry Pi.

#### Få inn riktig programvare

Vi skal nå få inn riktig programvare, samt laste inn alt av kode som skal ligge lokalt på Pien.

1. Start med å sjette at klokken inne på Raspberry Pien stemmer med kommandoen:

```bash
date
```

    * Dersom dato og klokken er feil kan du fikse opp i dette ved å bruke kommandoen (Husk å endre dato/klokkeslett til gjeldende tid):

```bash
sudo date -s '18 Aug 2022 13:00'
```

2. Nå kan du oppdatere og oppgradere med kommandoene

```bash
sudo apt-get update
sudo apt-get dist-upgrade
```

- Trykk enter når dem spør om du ønsker å fortsette.

3. Last ned libatlas og pyro4 med kommandoene:

```bash
sudo apt-get install libatlas-base-dev
sudo apt-get install python3-pyro4
```

4. Nå kan du klone git-en som inneholder koden som Raspberry Pi-en skal kjøre med kommandoen:

```bash
git clone https://gitlab.stud.idi.ntnu.no/ELSYS_teknostart/teknobil2022.git
```
