/*
Project 3 - Part 1d / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3. 
Part1 will be broken up into 5 separate steps 
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************
0) move 5-9 to between your Thing 4 and Thing 10.

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine` and 
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
*/



/*
Thing 1) Burger Shack
5 properties:
    1) total profit per day
    2) number of burgers served per day
    3) number of topping options
    4) amount of beef used per week
    5) days since the grease trap was last cleaned
3 things it can do:
    1) serve a burger w/fries
    2) charge the customer
    3) clean the grill
 */

/*
Thing 2) Fishing Trawler
5 properties:
    1) number of fishing nets on board
    2) number of crew members on board
    3) amount of fish caught per day
    4) amount of gas remaining
    5) distance covered per week
3 things it can do:
    1) pull in the nets
    2) turn to port
    3) clean the barnacles off of the hull
 */

/*
Thing 3) Dog
5 properties:
    1) distance traveled per day
    2) amount of food eaten per day
    3) top speed
    4) age
    5) weight
3 things it can do:
    1) roll over
    2) greet owners
    3) go to sleep
 */

/*
Thing 4) Steam Locomotive
5 properties:
    1) number of cars on train
    2) amount of coal used per day
    3) age
    4) horsepower
    5) number of crew on locomotive
3 things it can do:
    1) detach from currently coupled train car
    2) add more coal to the furnace
    3) slam on the brakes
 */


/*
Thing 5) Screen
5 properties:
    1) brightness (nits)
    2) diagonal screen size
    3) pixels per inch
    4) refresh rate
    5) color temperature
3 things it can do:
    1) adjust the brightness
    2) adjust the color temperature
    3) draw and display a new image
 */

/*
Thing 6) Keyboard
5 properties:
    1) number of keys
    2) brightness of backlighting
    3) key travel distance
    4) latency
    5) delay until key repeat
3 things it can do:
    1) send key code for a single character to the driver on the computer
    2) perform the action specified by a function key
    3) turn on caps lock
 */

/*
Thing 7) Hard Drive
5 properties:
    1) total capacity
    2) currently used disk space
    3) data transfer rate
    4) power consumption
    5) latency
3 things it can do:
    1) store data to disk 
    2) retrieve data from disk
    3) partition hard drive
 */

/*
Thing 8) RAM
5 properties:
    1) number of slots
    2) capacity per slot (GB)
    3) clock speed (MHz)
    4) transfer rate (MB/s)
    5) power consumption
3 things it can do:
    1) load information into active memory
    2) remove information from active memory
    3) access information in active memory
 */

/*
Thing 9) Operating System
5 properties:
    1) OS version
    2) number of bits of processor (32/64)
    3) number of active jobs
    4) number of active threads
    5) number of input devices
3 things it can do:
    1) swap active job
    2) pass input to an application
    3) update operating system version
 */

/*
Thing 10) Laptop Computer
5 properties:
    1) Screen
    2) Keyboard
    3) Hard Drive
    4) RAM
    5) Operating System
3 things it can do:
    1) open an application
    2) search for wifi networks
    3) configure preferences
 */



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
