#include <duration.h>
#include "stdlib.h"
#include "assert.h"


 bool Duration::checkAndUpdateAlarm() 
    /* Function to check the if the alarm has been met
        if the alarm has been met i will return true and should pass the test */
    {
        if (time >= alarm)//checks if the alarms i bigger then the time
            {
                alarm = -1;//sets the alarm to -1 so it cant be reached since it has been reached already
                alarmHasBeenSet = false;//turns off the alarm
                return true; //returns true so we know that 
            }
        else 
        return false;//if the alarm havent been reached then return false
    }
    
    int Duration::getDuration()
    /* This function will simply give you the current time count */
    {
        return time; //just returns the time
    }


    Duration::Duration()
    /* Resets the "clock" */
    {
        time = 0; //resets the clock
    }

    Duration::Duration(int t)
    /* Sets duration without counts*/
    {
        assert(t>0); //makes sure that time isnt under 0
        time = t;//this can change to time.
    }

    bool Duration::tick(int dt)
    /* This Function increases the "clock" by integer input and check for the alarm */
    {
        assert(time >=0); //make sure that time is over or equal to 0
        time += dt; //makes a tick that plusses to the time so it raises with dt
        if (alarmHasBeenSet == true) //runs the code (checkandupdate alarm)
            checkAndUpdateAlarm(); //checks and updates the alarm if needed
        else
        return false;
    }

    bool Duration::tick()
    /*Single integer increase to the "clock" that also checks for alarm*/
    {
        assert(time >= 0);
        time++; //just adds 1 to the time 
        if (alarmHasBeenSet == true) //checks if alarm has been reached
            checkAndUpdateAlarm();
        else
            return false;
    }

    void Duration::setAlarm(int a)
    /* Sets alarm at a given number */
    {
       assert(a > time); //this makes sure that the alarm can be reached since it need to be over time
       alarm = a; //the input a changes the alarmtime
       alarmHasBeenSet = true; //changes the alarmHasBeenSet to true so we can check if the alarm is set or not
    }

    bool Duration::Checkalarm()
    /* This function will simply give you the current state of the alarm */
    {
        return alarmHasBeenSet; //just returns the alarm state.
    }
