/*
Project 3 - Part 1b / 5
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

1)  Fill in #1 - 4 with a random UDT in plain english
    These 4 UDTs do not need to be related.
        a) For each plain-english UDT, write out 5 traits or properties and 3 things it can do
        b) remember: these properties will eventually become primitives
*/

/*
 example:  
 
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - the amount of water used per week.
        - amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior

    Notice that I did not use "has a vacuum cleaner" or "Has eco-friendly cleaning supplies" as one of the properties
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "number of vacuum cleaners" and "number of eco-friendly cleaning supplies".  
    
    These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.
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
