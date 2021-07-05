/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function.

 4) For each instantiated UDT: 
        call some of those amended member functions in main().
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




/*
UDT #1
*/
struct BurgerShack
{
    int numBurgersServedPerDay, numToppingOptions, daysSinceGreaseTrapCleaned;
    float profitPerWeek, beefUsedPerWeek;
    
    BurgerShack();

    struct Customer
    {
        std::string name;
        bool isRegularCustomer;
        int customerNumber;
        float tipPercentage, dollarsInWallet;

        Customer();

        void payForMeal(float amountOwed, bool tip = true);
        float checkHowMuchSodaLeftInCup(bool removeLid = false);
        void getExtraNapkins(int numNapkins);
    };

    void serveBurger(Customer customer, bool withFries);
    float chargeCustomer(Customer customer, float discountPercentage);
    void cleanGrill(bool extraMessToClean);

    Customer nextCustomerInLine;
};

BurgerShack::BurgerShack()
{
    
    numBurgersServedPerDay = 576;
    numToppingOptions = 12;
    daysSinceGreaseTrapCleaned = 2;
    profitPerWeek = 745.32f;
    beefUsedPerWeek = 47.5f;
}

BurgerShack::Customer::Customer()
{
    name = "Dave";
    isRegularCustomer = false;
    customerNumber = 27;
    tipPercentage = 0.15f;
    dollarsInWallet = 53.24f;
}

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
    float estimatedAmountOfSodaLeft = removeLid ? 0.231f : 0.25f;

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
    int numFishingNets, numCrewMembers;
    float amountOfFishCaughtPerDay, amountOfGasRemaining, distanceTraveledPerWeek;

    FishingTrawler();

    void pullInNet(int netId);
    void turnToPort(int degrees);
    void cleanBarnaclesFromHull(bool inDrydock);
};

FishingTrawler::FishingTrawler()
{
    numFishingNets = 3;
    numCrewMembers = 4;
    amountOfFishCaughtPerDay = 323.4f;
    amountOfGasRemaining = 25.4f;
    distanceTraveledPerWeek = 134.3f;
}

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
    int age;
    float distanceTraveledPerDay, amountOfFoodEatenPerDay, topSpeed, weight;

    Dog();

    struct Owner
    {
        std::string name;
        bool hasDogTreats, toughDayAtWork;
        int age;
        float topSpeed;
        
        Owner();

        void walkTheDog(float distanceToTravel, float initialSpeed = 5.3f);
        void feedTheDog(float amountOfFood, bool isDryFood = false);
        int checkDogForTicks(bool extraThorough = false);
    };

    void rollOver(bool toTheLeft);
    void greetOwner(Owner owner);
    void goToSleep(bool pleasantDreams);

    Owner ownerNancy;
};

Dog::Dog()
{
    age = 3;
    distanceTraveledPerDay = 3.4f;
    amountOfFoodEatenPerDay = 1.3f;
    topSpeed = 17.4f;
    weight = 43.2f;
}

Dog::Owner::Owner()
{
    name = "Nancy";
    hasDogTreats = true;
    toughDayAtWork = false;
    age = 42;
    topSpeed = 16.4f;
}


void Dog::rollOver(bool toTheLeft)
{  
    std::string rollDirection = toTheLeft ? "left." : "right.";

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
    std::string foodType = isDryFood ? "dry food" : "wet food";

    std::cout << "Fed the dog " << amountOfFood << "lbs of " << foodType << std::endl;
}

int Dog::Owner::checkDogForTicks(bool extraThorough)
{
    if(extraThorough)
    {
        return 3;
    }

    return 2;
}



/*
UDT #4
*/
struct SteamLocomotive
{
    int numCarsOnTrain, age, horsepower, numCrewMembers;
    float amountOfCoalUsedPerDay;

    SteamLocomotive();

    void detachFromCurrentTrainCar(bool warnCrew);
    void addCoalToFurnace(float lbsCoalToAdd);
    void slamOnTheBrakes(int delayTime);
};

SteamLocomotive::SteamLocomotive()
{
    numCarsOnTrain = 15;
    age = 25;
    horsepower = 4532;
    numCrewMembers = 2;
    amountOfCoalUsedPerDay = 7.5f;
}


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
    int brightness, pixelsPerInch, refreshRate, colorTemperature;
    float diagonalScreenSize;

    Screen();

    struct PixelMap
    {
        int numPixelsX, numPixelsY, colorDepth;
        float numMegapixels;
        std::string aspectRatio;
        
        PixelMap();

        void setPixelToColor(int pixelX, int pixelY, int r, int g, int b);
        void scaleResolution(int desiredResolutionX, int desiredResolutionY);
        int getRedLevelOfTriad(int pixelX, int pixelY);
    };

    void adjustBrightness(int newBrightness);
    void adjustColorTemperature(int newColorTemperature);
    void drawAndDisplayNewImage(PixelMap pixelMap);
};

Screen::Screen()
{
    brightness = 500;
    pixelsPerInch = 227;
    refreshRate = 60;
    colorTemperature = 6500;
    diagonalScreenSize = 13.3f;
}

Screen::PixelMap::PixelMap()
{
    numPixelsX = 2560;
    numPixelsY = 1600;
    colorDepth = 24;
    numMegapixels = 4.096f;
    aspectRatio = "16:10";
}

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
    int numKeys, backlightingBrightness;
    float travelDistance, latency, delayUntilKeyRepeat;

    Keyboard();

    int sendCharacterCodeToDriver(char character);
    void triggerFunctionKeyAction(int functionKeyId);
    void capsLockToggle(bool toStateOn);
};

Keyboard::Keyboard()
{
    numKeys = 109;
    backlightingBrightness = 750;
    travelDistance = 0.5f;
    latency = 2.4f;
    delayUntilKeyRepeat = 5.6f;
}


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
    std::string state = toStateOn ? "ON." : "OFF.";

    std::cout << "Set caps lock state to " << state << std::endl;
}

/*
UDT #7
*/
struct HardDrive
{
    int totalCapacity, dataTransferRate;
    float currentlyUsedDiskSpace, powerConsumption, latency;

    HardDrive();

    struct DataBlock
    {
        std::string dateCreated, dateLastAccessed, fileName;
        bool isLocked;
        double size;

        DataBlock();

        std::string getRelativePath(bool hideExtension = false);
        void setFlag(std::string flagToSet);
        void setDefaultApplication(int applicationId);
    };

    void storeDataToDisk(DataBlock dataBlock); 
    DataBlock retrieveDataFromDisk(int address);    
    void partitionHardDrive(int sizeOfPartition);
};

HardDrive::HardDrive()
{
    totalCapacity = 500;
    dataTransferRate = 550;
    currentlyUsedDiskSpace = 356.43f;
    powerConsumption = 2.7f;
    latency = 1.2f;
}

HardDrive::DataBlock::DataBlock()
{
    dateCreated = "3/12/2020";
    dateLastAccessed = "4/06/2020";
    fileName = "data.txt";
    isLocked = false;
    size = 3.2e6;
}


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
    std::string relativePath = hideExtension ? "block" : "block.txt";

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
    int numSlots, ramCapacityPerSlot, clockSpeed;
    float transferRate, powerConsumption;

    RAM();

    struct MemoryBlock
    {
        int size;
        bool isSRAM, currentlyBeingAccessed, overheating;
        double msSinceLastAccess;

        MemoryBlock();

        int getCellStatus(int x, int y);
        void setCacheLevel(int cacheLevel);
        void flagAsCacheMiss(std::string alertMessage);
    };

    int loadIntoActiveMemory(int address, int sizeOfMemoryBlock);
    void removeFromActiveMemory(MemoryBlock memoryBlock);
    MemoryBlock accessFromActiveMemory(int address);
};

RAM::RAM()
{
    numSlots = 2;
    ramCapacityPerSlot = 8;
    clockSpeed = 1600;
    transferRate = 12.8f;
    powerConsumption = 2.75f;
}

RAM::MemoryBlock::MemoryBlock()
{
    size = 2.45e4;
    isSRAM = false;
    currentlyBeingAccessed = false;
    overheating = false;
    msSinceLastAccess = 45;
}


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
    int processorBits, numActiveProcesses, numActiveThreads, numInputDevices;
    float osVersion;

    OperatingSystem();

    void swapActiveJob(int newJobIndex);
    void passInputToApplication(int applicationId);
    void updateOperatingSystemVersion(bool waitUntilTonight);
};

OperatingSystem::OperatingSystem()
{
    processorBits = 64;
    numActiveProcesses = 372;
    numActiveThreads = 1960;
    numInputDevices = 5;
    osVersion = 12.3f;
}


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
    LaptopComputer();

    void openApplication(int applicationId);
    std::string searchForWifiNetworks(bool trustedNetworksOnly);
    void configurePreferences(bool flagAsUpdateReady);
};

LaptopComputer::LaptopComputer()
{
    Screen screen;
    Keyboard keyboard;
    HardDrive hardDrive;
    RAM ram;
    OperatingSystem operatingSystem;
}


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
    Example::main();
    std::cout << "good to go!" << std::endl;
}
