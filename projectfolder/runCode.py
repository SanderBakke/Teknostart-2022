from doctest import FAIL_FAST
import os
from pickle import FALSE
import subprocess
from tkinter import LEFT, RIGHT
from turtle import down
import Pyro4
from core import WebMethod
import RPi.GPIO as GPIO



#set GPIO numbering mode and define output pins
GPIO.setmode(GPIO.BCM)

GPIO.setup(6,GPIO.OUT) #UP/DRIVE
GPIO.setup(13,GPIO.OUT) #DOWN/REVERSE
GPIO.setup(19,GPIO.OUT) #LEFT
GPIO.setup(26,GPIO.OUT) #RIGHT

UP = False
DOWN = False
RIGHT = False
LEFT =False



GPIO.setup(22,GPIO.OUT) #FORWARD DRIVING LIGHTS (YELLOW)
GPIO.setup(27,GPIO.OUT) #BACKWARDS DRIVING LIGHTS (RED)



def control_motors():   
    with Pyro4.Proxy("PYRONAME:KeyManager") as keys:
        with Pyro4.Proxy("PYRONAME:ROVSyncer") as rov:
            while rov.run:
                if keys.state('K_UP'):
                    print('Forward')
                    UP = True
                else:
                    UP = False
                if keys.state('K_DOWN'):
                    print('Down')
                    DOWN = True
                else:
                    DOWN = False
                if keys.state('K_RIGHT'):
                    print('Rigth')
                    RIGHT = True
                else:
                    RIGHT = False
                if keys.state('K_LEFT'):
                    print('Left')
                    LEFT = True
                else:
                    LEFT = False
                    
                FRONTLIGHTS = UP
                BACKLIGHTS = DOWN
                
                GPIO.output(6,UP)
                GPIO.output(13,DOWN)
                GPIO.output(19,LEFT)
                GPIO.output(26,RIGHT)
                GPIO.output(22, FRONTLIGHTS)
                GPIO.output(27,BACKLIGHTS)


# Create the WebMethod class
web_method = WebMethod(
    index_file=os.path.join(os.path.dirname(__file__), 'index.html'),
    runtime_functions=control_motors
)
# Start serving the web page, blocks the program after this point
web_method.serve()