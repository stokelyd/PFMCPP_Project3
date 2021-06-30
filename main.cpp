/*
Project 3 - Part 1e / 5
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

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};


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

struct BurgerShack
{
    // total profit per day
    float profitPerWeek = 745.32f;
    // number of burgers served per day
    int numBurgersServedPerDay = 576;
    // number of topping options
    int numToppingOptions = 12;
    // amount of beef used per week (lbs)
    float beefUsedPerWeek = 47.5f;
    // days since the grease trap was last cleaned
    int daysSinceGreaseTrapCleaned = 2;
    
    // nested UDT #1
    struct Customer
    {
        std::string name = "Dave";
        int customerNumber = 27;
        bool isRegularCustomer = false;
        float tipPercentage = 0.15f;
        float dollarsInWallet = 53.24f;

        void payForMeal(float amountOwed, bool tip = true);
        float checkHowMuchSodaLeftInCup(bool removeLid = false);
        void getExtraNapkins(int numNapkins);
    };

    // serve a burger w/fries
    void serveBurger(Customer customer, bool withFries);
    // charge the customer
    float chargeCustomer(Customer customer, float discountPercentage);
    // clean the grill
    void cleanGrill(bool extraMessToClean);

    Customer nextCustomerInLine;
};

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

struct FishingTrawler
{
    // number of fishing nets on board
    int numFishingNets = 3;
    // number of crew members on board
    int numCrewMembers = 4;
    // amount of fish caught per day (lbs)
    float amountOfFishCaughtPerDay = 323.4f;
    // amount of gas remaining (gallons)
    float amountOfGasRemaining = 25.4f;
    // distance traveled per week (km)
    float distanceTraveledPerWeek = 134.3f;

    // pull in the nets
    void pullInNet(int netId);
    // turn to port
    void turnToPort(int degrees);
    // clean the barnacles off of the hull
    void cleanBarnaclesFromHull(bool inDrydock);
};

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

struct Dog
{
    // distance traveled per day (km)
    float distanceTraveledPerDay = 3.4f;
    // amount of food eaten per day (lbs)
    float amountOfFoodEatenPerDay = 1.3f;
    // top speed (km/hr)
    float topSpeed = 17.4f;
    // age (yrs)
    int age = 3;
    // weight (lbs)
    float weight = 43.2f;

    // Nested UDT #2
    struct Owner
    {
        std::string name = "Nancy";
        int age = 42;
        bool hasDogTreats = true;
        float topSpeed = 16.4f;
        bool toughDayAtWork = false;

        void walkTheDog(float distanceToTravel, float initialSpeed = 5.3f);
        void feedTheDog(float amountOfFood, bool isDryFood = false);
        int checkDogForTicks(bool extraThorough = false);
    };

    // roll over
    void rollOver(bool toTheLeft);
    // greet owners
    void greetOwner(Owner owner);
    // go to sleep
    void goToSleep(bool pleasantDreams);

    Owner owner;
};

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

struct SteamLocomotive
{
    // number of cars on train
    int numCarsOnTrain = 15;
    // amount of coal used per day (tons)
    float amountOfCoalUsedPerDay = 7.5f;
    // age (yrs)
    int age = 25;
    // horsepower
    int horsepower = 4532;
    // number of crew on locomotive
    int numCrewMembers = 2;

    // detach from currently coupled train car
    void detachFromCurrentTrainCar(bool warnCrew);
    // add more coal to the furnace
    void addCoalToFurnace(float lbsCoalToAdd);
    // slam on the brakes
    void slamOnTheBrakes(int delayTime);
};

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

struct Screen
{
    // brightness (nits)
    int brightness = 500;
    // diagonal screen size (inches)
    float diagonalScreenSize = 13.3f;
    // pixels per inch
    int pixelsPerInch = 227;
    // refresh rate (Hz)
    int refreshRate = 60;
    // color temperature (K)
    int colorTemperature = 6500;

    // dummy struct to stand in for a screen image to be rendered
    struct PixelMap
    {
    };

    // adjust the brightness
    void adjustBrightness(int newBrightness);
    // adjust the color temperature
    void adjustColorTemperature(int newColorTemperature);
    // draw and display a new image
    void drawAndDisplayNewImage(PixelMap pixelMap);
};

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
    2) trigger the action specified by a function key
    3) turn on caps lock
 */

struct Keyboard
{
    // number of keys
    int numKeys = 109;
    // brightness of backlighting (lumens)
    int backlightingBrightness = 750;
    // key travel distance (mm)
    float travelDistance = 0.5f;
    // latency (ms)
    float latency = 2.4f;
    // delay until key repeat (ms)
    float delayUntilKeyRepeat = 5.6f;

    // send key code for a single character to the driver on the computer
    int sendCharacterCodeToDriver(char character);
    // trigger the action specified by a function key
    void triggerFunctionKeyAction(int functionKeyId);
    // turn on caps lock
    void capsLockToggle(bool toStateOn);
};

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

struct HardDrive
{
    // total capacity (GB)
    int totalCapacity = 500;
    // currently used disk space
    float currentlyUsedDiskSpace = 356.43f;
    // data transfer rate (MBps)
    int dataTransferRate = 550;
    // power consumption (W)
    float powerConsumption = 2.7f;
    // latency (ms)
    float latency = 1.2f;

    // dummy struct representing a block of memory
    struct DataBlock
    {
    };

    // store data to disk
    void storeDataToDisk(DataBlock dataBlock); 
    // retrieve data from disk
    DataBlock retrieveDataFromDisk(int address);    
    // partition hard drive
    void partitionHardDrive(int sizeOfPartition);
};

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

struct RAM
{
    // number of slots
    int numSlots = 2;
    // capacity per slot (GB)
    int ramCapacityPerSlot = 8;
    // clock speed (MHz)
    int clockSpeed = 1600;
    // transfer rate (GB/s)
    float transferRate = 12.8f;
    // power consumption (W)
    float powerConsumption = 2.75f;

    // dummy struct representing a block of active memory
    struct MemoryBlock
    {
    };

    // load information into active memory (return address)
    int loadIntoActiveMemory(int address, int sizeOfMemoryBlock);
    // remove information from active memory
    void removeFromActiveMemory(MemoryBlock memoryBlock);
    // access information in active memory
    MemoryBlock accessFromActiveMemory(int address);
};

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

 struct OperatingSystem
 {
    // OS version
    float osVersion = 12.3f;
    // number of bits of processor (32/64)
    int processorBits = 64;
    // number of active processes
    int numActiveProcesses = 372;
    // number of active threads
    int numActiveThreads = 1960;
    // number of input devices
    int numInputDevices = 5;

    // swap active job
    void swapActiveJob(int newJobIndex);
    // pass input to an application
    void passInputToApplication(int applicationId);
    // update operating system version
    void updateOperatingSystemVersion(bool waitUntilTonight);
 };

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

struct LaptopComputer
{
    // Screen
    Screen screen;
    // Keyboard
    Keyboard keyboard;
    // Hard Drive
    HardDrive hardDrive;
    // RAM
    RAM ram;
    // Operating System
    OperatingSystem operatingSystem;

    // open an application
    void openApplication(int applicationId);
    // search for wifi networks
    std::string searchForWifiNetworks(bool trustedNetworksOnly);
    // configure preferences
    void configurePreferences(bool flagAsUpdateReady);
};



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
