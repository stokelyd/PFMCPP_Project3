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

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Foot
    {
        int lengthOfStride = 30;

        void stepForward();
        int stepSize();
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
    std::cout << "Two steps taken at " << howFast << "km/hr" << std::endl;
}

void Person::Foot::stepForward()
{
}

int Person::Foot::stepSize()
{
    return lengthOfStride;
}


 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 */


/*
UDT #1
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

void BurgerShack::serveBurger(Customer customer, bool withFries)
{
    std::cout << "Served burger to " << customer.name << std::endl;
    if(withFries)
    {
        std::cout << "with a side of fries" << std::endl;
    }
}

float BurgerShack::chargeCustomer(Customer customer, float discountPercentage)
{
    float costOfMeal = 5.75f;
    float amountToCharge = costOfMeal - (costOfMeal * discountPercentage);

    std::cout << "Charged " << customer.name << amountToCharge << "dollars";
    return amountToCharge;
}

void cleanGrill(bool extraMessToClean)
{
    std::cout << "Cleaned the grill..." << std::endl;

    if(extraMessToClean)
    {
        std::cout << "...it was really gross." << std::endl;   
    }
}


void BurgerShack::Customer::payForMeal(float amountOwed, bool tip)
{
    if(tip)
    {
        amountOwed += amountOwed * 0.15f;
    }

    std::cout << "Paid " << amountOwed << "dollars" << std::endl;
}

float BurgerShack::Customer::checkHowMuchSodaLeftInCup(bool removeLid)
{
    float estimatedAmountOfSodaLeft;

    if(removeLid)
    {
        estimatedAmountOfSodaLeft = 0.231f;
    }
    else
    {
        estimatedAmountOfSodaLeft = 0.25f;
    }

    return estimatedAmountOfSodaLeft;
}

void BurgerShack::Customer::getExtraNapkins(int numNapkins)
{
    std::cout << "Got " << numNapkins << " extra napkins" << std::endl;
}



/*
UDT #2
*/
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

void FishingTrawler::pullInNet(int netId)
{
    std::cout << "Pulled in net #" << netId << std::endl;
}

void FishingTrawler::turnToPort(int degrees)
{
    std::cout << "Turned " << degrees << " degrees to port";
}

void FishingTrawler::cleanBarnaclesFromHull(bool inDrydock)
{
    std::cout << "Cleaned the barnacles off of the hull" << std::endl;

    if(inDrydock)
    {
        std::cout << "(very thoroughly, b/c the boat was in drydock)";
    }
}


/*
UDT #3
*/
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

    Owner ownerNancy;
};

void Dog::rollOver(bool toTheLeft)
{  
    std::string rollDirection;
    if(toTheLeft)
    {
        rollDirection = "left.";
    }
    else
    {
        rollDirection = "right.";
    }

    std::cout << "Rolled over to the " << rollDirection << std::endl;   
}

void Dog::greetOwner(Owner owner)
{
    std::cout << "Said hello to " << owner.name << std::endl; 
}

void Dog::goToSleep(bool pleasantDreams)
{
    std::cout << "Went to sleep..." << std::endl;

    if(pleasantDreams)
    {
        std::cout << "...and slept peacefully." << std::endl;
    }
    else
    {
        std::cout << "...but had nightmares." << std::endl;
    }
}


void Dog::Owner::walkTheDog(float distanceToTravel, float initialSpeed)
{
    std::cout << "Took the dog for a walk, starting at " << initialSpeed << "km/hr and traveling " << distanceToTravel << "km." << std::endl;
}

void Dog::Owner::feedTheDog(float amountOfFood, bool isDryFood)
{
    std::string foodType;
    if(isDryFood)
    {
        foodType = "dry food";
    }
    else
    {
        foodType = "wet food";
    }

    std::cout << "Fed the dog " << amountOfFood << "lbs of " << foodType << std::endl;
}

int Dog::Owner::checkDogForTicks(bool extraThorough)
{
    if(extraThorough)
    {
        return 3;
    }
    else
    {
        return 2;
    }
}



/*
UDT #4
*/
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

void SteamLocomotive::detachFromCurrentTrainCar(bool warnCrew)
{
    if(warnCrew)
    {
        std::cout << "Warned the crew and..." << std::endl;
    }

    std::cout << "Detached the locomotive from the currently attached train car." << std::endl;
}

void SteamLocomotive::addCoalToFurnace(float lbsCoalToAdd)
{
    std::cout << "Added " << lbsCoalToAdd << "lbs of coal to the furnace." << std::endl;
}

void SteamLocomotive::slamOnTheBrakes(int delayTime)
{
    std::cout << "After " << delayTime << " seconds, slammed on the brakes" << std::endl;
}


/*
UDT #5
*/
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

void Screen::adjustBrightness(int newBrightness)
{
    std::cout << "Set the screen brightness to " << newBrightness << "nits." << std::endl;
}

void Screen::adjustColorTemperature(int newColorTemperature)
{
    std::cout << "set the screen color temperature to " << newColorTemperature << " K." << std::endl;
}

void Screen::drawAndDisplayNewImage(PixelMap pixelMap)
{
    std::cout << "Drew and displayed a new image at aspect ratio " << pixelMap.aspectRatio << std::endl;
}


void Screen::PixelMap::setPixelToColor(int pixelX, int pixelY, int r, int g, int b)
{
    std::cout << "Set to pixel at coordinates " << pixelX << ", " << pixelY << " to rgb value " << r << g << b << std::endl;
}

void Screen::PixelMap::scaleResolution(int desiredResolutionX, int desiredResolutionY)
{
    std::cout << "scale mapped pixel resolution to " << desiredResolutionX << " x " << desiredResolutionY << std::endl;
}

int Screen::PixelMap::getRedLevelOfTriad(int pixelX, int pixelY)
{
    int dummyRedLevel = 146;
    std::cout << "Get the red vales of the triad at location " << pixelX << ", " << pixelY << std::endl;
    return dummyRedLevel;
}



/*
UDT #6
*/
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

int Keyboard::sendCharacterCodeToDriver(char character)
{
    int asciiCode = int(character);
    std::cout << "Sent the ASCII code " << asciiCode << " to the driver." << std::endl;
    return asciiCode;
}

void Keyboard::triggerFunctionKeyAction(int functionKeyId)
{
    std::cout << "Triggered the function associated with keyId " << functionKeyId << std::endl;
}
void Keyboard::capsLockToggle(bool toStateOn)
{
    std::string state;
    if (toStateOn)
    {
        state = "ON.";
    }
    else
    {
        state = "OFF.";
    }

    std::cout << "Set caps lock state to " << state << std::endl;
}

/*
UDT #7
*/
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

void HardDrive::storeDataToDisk(DataBlock dataBlock)
{
    std::cout << "Stored the block of data with filename " << dataBlock.fileName << " to disk." << std::endl;
}

HardDrive::DataBlock HardDrive::retrieveDataFromDisk(int address)
{
    DataBlock dummyRetrivalBlock;
    std::cout << "Retrived the block of data from address " << address << std::endl;
    return dummyRetrivalBlock;
}

void HardDrive::partitionHardDrive(int sizeOfPartition)
{
    std::cout << "Created a new partition of size " << sizeOfPartition << "bits." << std::endl;
}


std::string HardDrive::DataBlock::getRelativePath(bool hideExtension)
{
    std::string relativePath;
    if (hideExtension)
    {
        relativePath = "block";
    }
    else
    {
        relativePath = "block.txt";
    }

    return relativePath;
}

void HardDrive::DataBlock::setFlag(std::string flagToSet)
{
    std::cout << "Set flag " << flagToSet << std::endl;
}

void HardDrive::DataBlock::setDefaultApplication(int applicationId)
{
    std::cout << "Set default application to the application with ID " << applicationId << std::endl;
}



/*
UDT #8
*/
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

int RAM::loadIntoActiveMemory(int address, int sizeOfMemoryBlock)
{
    int activeMemoryAddress = 35423;
    std::cout << "Loaded " << sizeOfMemoryBlock << " bits from address " << address << "into active memory at address " << activeMemoryAddress << std::endl;
    return activeMemoryAddress;
}

void RAM::removeFromActiveMemory(MemoryBlock memoryBlock)
{
    std::cout << "Removed a block of memory of size " << memoryBlock.size << " from active memory" << std::endl;
}

RAM::MemoryBlock RAM::accessFromActiveMemory(int address)
{
    MemoryBlock dummyRetrivalBlock;
    std::cout << "Accessed the memory block at address " << address << std::endl;
    return dummyRetrivalBlock;
}


int RAM::MemoryBlock::getCellStatus(int x, int y)
{
    int status = 1;
    std::cout << "Get the status of the cell at " << x << ", " << y << std::endl;
    return status;
}

void RAM::MemoryBlock::setCacheLevel(int cacheLevel)
{
    std::cout << "Set cache level to " << cacheLevel << std::endl;
}

void RAM::MemoryBlock::flagAsCacheMiss(std::string alertMessage)
{
    std::cout << "Cache miss with message " << alertMessage << std::endl;
}



/*
UDT #9
*/
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

void OperatingSystem::swapActiveJob(int newJobIndex)
{
    std::cout << "Swapped active job to the job at index " << newJobIndex << std::endl;
}
void OperatingSystem::passInputToApplication(int applicationId)
{
    std::cout << "Passed device input to the application with ID " << applicationId << std::endl;
}

void OperatingSystem::updateOperatingSystemVersion(bool waitUntilTonight)
{
    if (waitUntilTonight)
    {
        std::cout << "The OS will update later tonight." << std::endl;
    }
    else
    {
        std::cout << "The OS will now update." << std::endl;
    }
}



/*
UDT #10
*/
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

void LaptopComputer::openApplication(int applicationId)
{
    std::cout << "Opened the application with ID " << applicationId << std::endl;
}

std::string LaptopComputer::searchForWifiNetworks(bool trustedNetworksOnly)
{
    std::string someSketchyNetwork = "123579283asfgh";

    if (trustedNetworksOnly)
    {
        std::cout << "No trusted networks found, expand search?" << std::endl;
        return std::string();
    }
    else
    {
        std::cout << "Found network: " << someSketchyNetwork << std::endl;
        return someSketchyNetwork;
    }
}

void LaptopComputer::configurePreferences(bool flagAsUpdateReady)
{
    std::cout << "Opening preferences window..." << std::endl;

    if(flagAsUpdateReady)
    {
        std::cout << "Alert: an update is available." << std::endl;
    }
}

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
