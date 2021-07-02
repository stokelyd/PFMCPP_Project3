 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 */



struct BurgerShack
{
    float profitPerWeek = 745.32f;
    int numBurgersServedPerDay = 576;
    int numToppingOptions = 12;
    float beefUsedPerWeek = 47.5f;
    int daysSinceGreaseTrapCleaned = 2;
    
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

    void serveBurger(Customer customer, bool withFries);
    float chargeCustomer(Customer customer, float discountPercentage);
    void cleanGrill(bool extraMessToClean);

    Customer nextCustomerInLine;
};



struct FishingTrawler
{
    int numFishingNets = 3;
    int numCrewMembers = 4;
    float amountOfFishCaughtPerDay = 323.4f;
    float amountOfGasRemaining = 25.4f;
    float distanceTraveledPerWeek = 134.3f;

    void pullInNet(int netId);
    void turnToPort(int degrees);
    void cleanBarnaclesFromHull(bool inDrydock);
};



struct Dog
{
    float distanceTraveledPerDay = 3.4f;
    float amountOfFoodEatenPerDay = 1.3f;
    float topSpeed = 17.4f;
    int age = 3;
    float weight = 43.2f;

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

    void rollOver(bool toTheLeft);
    void greetOwner(Owner owner);
    void goToSleep(bool pleasantDreams);

    Owner owner;
};



struct SteamLocomotive
{
    int numCarsOnTrain = 15;
    float amountOfCoalUsedPerDay = 7.5f;
    int age = 25;
    int horsepower = 4532;
    int numCrewMembers = 2;

    void detachFromCurrentTrainCar(bool warnCrew);
    void addCoalToFurnace(float lbsCoalToAdd);
    void slamOnTheBrakes(int delayTime);
};



struct Screen
{
    int brightness = 500;
    float diagonalScreenSize = 13.3f;
    int pixelsPerInch = 227;
    int refreshRate = 60;
    int colorTemperature = 6500;

    struct PixelMap
    {
        int numPixelsX = 2560;
        int numPixelsY = 1600;
        float numMegapixels = 4.096f;
        int colorDepth = 24;
        std::string aspectRatio = "16:10";

        void setPixelToColor(int pixelX, int pixelY, int r, int g, int b);
        void scaleResolution(int desiredResolutionX, int desiredResolutionY);
        int getRedLevelOfTriad(int pixelX, int pixelY);
    };

    void adjustBrightness(int newBrightness);
    void adjustColorTemperature(int newColorTemperature);
    void drawAndDisplayNewImage(PixelMap pixelMap);
};



struct Keyboard
{
    int numKeys = 109;
    int backlightingBrightness = 750;
    float travelDistance = 0.5f;
    float latency = 2.4f;
    float delayUntilKeyRepeat = 5.6f;

    int sendCharacterCodeToDriver(char character);
    void triggerFunctionKeyAction(int functionKeyId);
    void capsLockToggle(bool toStateOn);
};



struct HardDrive
{
    int totalCapacity = 500;
    float currentlyUsedDiskSpace = 356.43f;
    int dataTransferRate = 550;
    float powerConsumption = 2.7f;
    float latency = 1.2f;

    struct DataBlock
    {
        double size = 3.2e6;
        std::string dateCreated = "3/12/2020";
        std::string dateLastAccessed = "4/06/2020";
        std::string fileName = "data.txt";
        bool isLocked = false;

        std::string getRelativePath(bool hideExtension = false);
        void setFlag(std::string flagToSet);
        void setDefaultApplication(int applicationId);
    };

    void storeDataToDisk(DataBlock dataBlock); 
    DataBlock retrieveDataFromDisk(int address);    
    void partitionHardDrive(int sizeOfPartition);
};



struct RAM
{
    int numSlots = 2;
    int ramCapacityPerSlot = 8;
    int clockSpeed = 1600;
    float transferRate = 12.8f;
    float powerConsumption = 2.75f;

    struct MemoryBlock
    {
        int size = 2.45e4;
        bool isSRAM = false;
        bool currentlyBeingAccessed = false;
        double msSinceLastAccess = 45;
        bool overheating = false;

        int getCellStatus(int x, int y);
        void setCacheLevel(int cacheLevel);
        void flagAsCacheMiss(std::string alertMessage);
    };

    int loadIntoActiveMemory(int address, int sizeOfMemoryBlock);
    void removeFromActiveMemory(MemoryBlock memoryBlock);
    MemoryBlock accessFromActiveMemory(int address);
};



struct OperatingSystem
{
    float osVersion = 12.3f;
    int processorBits = 64;
    int numActiveProcesses = 372;
    int numActiveThreads = 1960;
    int numInputDevices = 5;

    void swapActiveJob(int newJobIndex);
    void passInputToApplication(int applicationId);
    void updateOperatingSystemVersion(bool waitUntilTonight);
};



struct LaptopComputer
{
    Screen screen;
    Keyboard keyboard;
    HardDrive hardDrive;
    RAM ram;
    OperatingSystem operatingSystem;

    void openApplication(int applicationId);
    std::string searchForWifiNetworks(bool trustedNetworksOnly);
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
