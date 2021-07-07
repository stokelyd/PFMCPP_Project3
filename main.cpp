/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





/*
UDT #1
*/
struct BurgerShack
{
    int numBurgersServedPerDay, numToppingOptions, daysSinceGreaseTrapCleaned;
    float profitPerWeek { 745.32f }, beefUsedPerWeek { 47.5f };
    
    BurgerShack() : numBurgersServedPerDay(576), numToppingOptions(12)
    {
        daysSinceGreaseTrapCleaned = 2;
    }

    struct Customer
    {
        std::string name = "Dave";
        bool isRegularCustomer = false;
        int customerNumber;
        float tipPercentage, dollarsInWallet;

        Customer() : customerNumber(27)
        {
            tipPercentage = 0.15f;
            dollarsInWallet = 53.24f;
        }

        void payForMeal(float amountOwed, bool tip = true);
        float checkHowMuchSodaLeftInCup(bool removeLid = false);
        void getExtraNapkins(int numNapkins);
    };

    void serveBurger(Customer customer, bool withFries);
    float chargeCustomer(Customer customer, float discountPercentage);
    void cleanGrill(bool extraMessToClean);

    bool isItTimeToCleanTheGreaseTrap(int cleaningThreshold, int numDaysElapsed = 7);

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

void BurgerShack::cleanGrill(bool extraMessToClean)
{
    std::cout << "Cleaned the grill..." << std::endl;

    if(extraMessToClean)
    {
        std::cout << "...it was really gross, probably because the shack uses " << beefUsedPerWeek << "lbs of meat per week." << std::endl;   
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

bool BurgerShack::isItTimeToCleanTheGreaseTrap(int cleaningThreshold, int numDaysElapsed)
{
    int currentGreaseTrapStatus = daysSinceGreaseTrapCleaned;

    while (currentGreaseTrapStatus < cleaningThreshold)
    {
        currentGreaseTrapStatus++;

        if (currentGreaseTrapStatus >= cleaningThreshold)
        {
            daysSinceGreaseTrapCleaned += numDaysElapsed;
            return true;
        }
    }

    daysSinceGreaseTrapCleaned += numDaysElapsed;
    return false;    
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

    void setSailForNumDays(int numDaysToSailFor, float amountFuelUsedPerDay = 6.94f);
};

FishingTrawler::FishingTrawler() : numFishingNets(5), numCrewMembers(4), amountOfFishCaughtPerDay(323.4f)
{
    amountOfGasRemaining = 25.4f;
    distanceTraveledPerWeek = 134.3f;
}

void FishingTrawler::pullInNet(int netId)
{
    std::cout << "Pulled in net #" << netId << " out of " << numFishingNets << " total fishing nets." << std::endl;
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

void FishingTrawler::setSailForNumDays(int numDaysToSailFor, float amountFuelUsedPerDay)
{
    float totalNumFishCaught = 0.f;

    for (int i = 1; i <= numDaysToSailFor; ++i)
    {
        if (amountOfGasRemaining >= amountFuelUsedPerDay)
        {
            amountOfGasRemaining -= amountFuelUsedPerDay;
            totalNumFishCaught += amountOfFishCaughtPerDay;

            std::cout << "Day " << i << ": Caught " << amountOfFishCaughtPerDay << "lbs of fish today, for a total of " << totalNumFishCaught << "lbs.\n";
        }
        else
        {
            std::cout << "Out of gas...\n";
            break;
        }
    }

    std::cout << "In total, caught " << totalNumFishCaught << "lbs of fish.\n";
}

/*
UDT #3
*/
struct Dog
{
    int age { 3 };
    float distanceTraveledPerDay, amountOfFoodEatenPerDay;
    float topSpeed { 17.4f }, weight { 43.2f };

    Dog();

    struct Owner
    {
        std::string name { "Nancy" };
        bool hasDogTreats, toughDayAtWork;
        int age { 42 };
        float topSpeed;
        
        Owner();

        void walkTheDog(float distanceToTravel, float initialSpeed = 5.3f);
        void feedTheDog(float amountOfFood, bool isDryFood = false);
        int checkDogForTicks(bool extraThorough = false);
    };

    void rollOver(bool toTheLeft);
    void greetOwner(Owner owner);
    void goToSleep(bool pleasantDreams);

    void doSomeTricks(int numToPerform);

    Owner ownerNancy;
};

Dog::Dog() : distanceTraveledPerDay(3.4f)
{
    amountOfFoodEatenPerDay = 1.3f;
}

Dog::Owner::Owner() : hasDogTreats(true), toughDayAtWork(false)
{
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
        std::cout << "...and slept peacefully," << std::endl;
    }
    else
    {
        std::cout << "...but had nightmares," << std::endl;
    }

    std::cout << "likely due to eating " << amountOfFoodEatenPerDay << "lbs of food today\n";
}

void Dog::doSomeTricks(int numToPerform)
{
    for (int i = 1; i <= numToPerform; ++i)
    {
        std::cout << "Did a trick (number " << i << "), and was rewarded\n";
    }

    ownerNancy.hasDogTreats = false;
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
    float amountOfCoalUsedPerDay { 7.5f };

    SteamLocomotive();

    void detachFromCurrentTrainCar(bool warnCrew);
    void addCoalToFurnace(float lbsCoalToAdd);
    void slamOnTheBrakes(int delayTime);

    void removeCarsFromTrain(int numCarsToRemove);
};

SteamLocomotive::SteamLocomotive() : numCarsOnTrain(15), age(25)
{
    horsepower = 4532;
    numCrewMembers = 2;
}


void SteamLocomotive::detachFromCurrentTrainCar(bool warnCrew)
{
    if(warnCrew)
    {
        std::cout << "Warned the crew and..." << std::endl;
    }

    std::cout << "Detached the locomotive from the currently attached train car: " << (numCarsOnTrain - 1) << " cars remaining.\n";
}

void SteamLocomotive::addCoalToFurnace(float lbsCoalToAdd)
{
    std::cout << "Added " << lbsCoalToAdd << "lbs of coal to the furnace." << std::endl;
}

void SteamLocomotive::slamOnTheBrakes(int delayTime)
{
    std::cout << "After " << delayTime << " seconds, slammed on the brakes" << std::endl;
}

void SteamLocomotive::removeCarsFromTrain(int numCarsToRemove)
{
    for (int i = 0; i < numCarsToRemove; ++i)
    {
        if (numCarsOnTrain > 0)
        {
            numCarsOnTrain--;
            std::cout << "Removed the last car from the train, leaving a total of " << numCarsOnTrain << " remaining\n";
        }
        else
        {
            std::cout << "All of the train cars have been removed...\n";
            break;
        }
    }
}


/*
UDT #5
*/
struct Screen
{
    int brightness, pixelsPerInch, refreshRate, colorTemperature;
    float diagonalScreenSize { 13.3f };

    Screen() : brightness(500), pixelsPerInch(227), refreshRate(60), colorTemperature(6500)
    {
    }

    struct PixelMap
    {
        int numPixelsX, numPixelsY, colorDepth;
        float numMegapixels { 4.096f };
        std::string aspectRatio { "16:10" };
        
        PixelMap();
        PixelMap(int x, int y);

        void setPixelToColor(int pixelX, int pixelY, int r, int g, int b);
        void scaleResolution(int desiredResolutionX, int desiredResolutionY);
        int getRedLevelOfTriad(int pixelX, int pixelY);
    };

    void adjustBrightness(int newBrightness);
    void adjustColorTemperature(int newColorTemperature);
    void drawAndDisplayNewImage(PixelMap pixelMap);

    PixelMap getNewPixelMapToDraw(int numPixelsX, int numPixelsY, std::string color);

    PixelMap screenImage;
};


Screen::PixelMap::PixelMap() : numPixelsX(2560), numPixelsY(1600)
{
    colorDepth = 24;
}

Screen::PixelMap::PixelMap(int x, int y) : numPixelsX(x), numPixelsY(y)
{
    colorDepth = 24;
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

Screen::PixelMap Screen::getNewPixelMapToDraw(int numPixelsX, int numPixelsY, std::string color)
{
    PixelMap pixelMap(3, 5);

    for (int i = 0; i < numPixelsX; ++i)
    {
        for (int j = 0; j < numPixelsY; ++j)
        {
            std::cout << i << ", " << j << ": " << color << "    ";
        }
        std::cout << std::endl;
    }

    return pixelMap;
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
    int numKeys { 109 }, backlightingBrightness { 500 };
    float travelDistance { 0.5f }, latency { 2.4f }, delayUntilKeyRepeat { 5.6f }; 

    Keyboard();

    int sendCharacterCodeToDriver(char character);
    void triggerFunctionKeyAction(int functionKeyId);
    void capsLockToggle(bool toStateOn);

    void adjustBacklightingBrightness(int numStepsToAdjust);
};

Keyboard::Keyboard()
{
}


int Keyboard::sendCharacterCodeToDriver(char character)
{
    int asciiCode = int(character);
    std::cout << "Sent the ASCII code " << asciiCode << " to the driver.\n";
    std::cout << "Note: there was a latency of " << latency << " performing this operation.\n";
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

void Keyboard::adjustBacklightingBrightness(int numStepsToAdjust)
{
    for (int i = 0; i < abs(numStepsToAdjust); ++i)
    {
        if (numStepsToAdjust > 0)
        {
            backlightingBrightness += 100;
            std::cout << "Increased keyboard brightness by one notch...\n";
        }
        else if (numStepsToAdjust < 0)
        {
            backlightingBrightness -= 100;
            std::cout << "Decreased keyboard brightness by one notch...\n";
        }

        std::cout << "Current brightness is: " << backlightingBrightness << std::endl;
        if (backlightingBrightness == 1000 || backlightingBrightness == 0)
        {
            break;
        }
    }
}

/*
UDT #7
*/
struct HardDrive
{
    int totalCapacity { 500 }, dataTransferRate { 550 };
    float currentlyUsedDiskSpace, powerConsumption, latency;

    HardDrive() : currentlyUsedDiskSpace(356.43f), powerConsumption(2.7f), latency(1.2f)
    {
    }

    struct DataBlock
    {
        std::string dateCreated { "3/12/2020" }, dateLastAccessed { "4/06/2020" }, fileName { "data.txt" };
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

    void formatHardDrive();
};


HardDrive::DataBlock::DataBlock() : isLocked(false)
{
    size = 3.2e6;
}


void HardDrive::storeDataToDisk(DataBlock dataBlock)
{
    std::cout << "Stored the block of data with filename " << dataBlock.fileName << " to disk.\n";
    std::cout << (totalCapacity - currentlyUsedDiskSpace) << "GB of disk space remaining.\n";
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

void HardDrive::formatHardDrive()
{
    for (int i = 10; i <= totalCapacity; i += 10)
    {
        if (i % 100 == 0)
        {
            std::cout << "Cleared " << i  << "gb out of " << totalCapacity << "gb.\n";
        }
    }

    currentlyUsedDiskSpace = 0.f;
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
    int numSlots { 2 }, ramCapacityPerSlot { 8 }, clockSpeed { 1600 };
    float transferRate, powerConsumption;

    RAM() : transferRate(12.8f), powerConsumption(2.75f)
    {
    }

    struct MemoryBlock
    {
        int size { 245000 };
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

    void overclockRAM(int desiredClockSpeed);

    MemoryBlock exampleMemoryBlock;
};

RAM::MemoryBlock::MemoryBlock() : msSinceLastAccess(45)
{
    isSRAM = false;
    currentlyBeingAccessed = false;
    overheating = false;
}


int RAM::loadIntoActiveMemory(int address, int sizeOfMemoryBlock)
{
    int activeMemoryAddress = 35423;
    std::cout << "Loaded " << sizeOfMemoryBlock << " bits from address " << address << " into active memory at address " << activeMemoryAddress << std::endl;
    std::cout << "Transfer rate = " << transferRate << "mb/s.\n" ;
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

void RAM::overclockRAM(int desiredClockSpeed)
{
    while (!exampleMemoryBlock.overheating)
    {
        if (desiredClockSpeed > clockSpeed)
        {
            clockSpeed += 100;
            std::cout << "Set clock speed to " << clockSpeed << std::endl;
        }

        if (clockSpeed >= 2000) 
        {
            exampleMemoryBlock.overheating = true;
            std::cout << "Warning: overheating\n";
        }
    }
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
    int processorBits { 64 }, numActiveProcesses { 372 }, numActiveThreads { 1960 }, numInputDevices { 5 };
    float osVersion;

    OperatingSystem();

    void swapActiveJob(int newJobIndex);
    void passInputToApplication(int applicationId);
    void updateOperatingSystemVersion(bool waitUntilTonight);

    void parseActiveProcesses(int mod);
};

OperatingSystem::OperatingSystem() : osVersion(12.3f)
{
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
        std::cout << "The OS will update later tonight.\n";
    }
    else
    {
        std::cout << "The OS will now update.\n";
    }

    std::cout << "Current OS Version: " << osVersion << "\n" << "Next OS Version: " << (osVersion + 0.01f) << "\n";
}

void OperatingSystem::parseActiveProcesses(int mod)
{
    for (int i = 0; i < numActiveProcesses; ++i)
    {
        if (i % mod == 0)
        {
            std::cout << i << " % " << mod << " = 0\n";
        }
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

    LaptopComputer();

    void openApplication(int applicationId);
    std::string searchForWifiNetworks(bool trustedNetworksOnly);
    void configurePreferences(bool flagAsUpdateReady);

    void closeAllAndShutdown();
};

LaptopComputer::LaptopComputer()
{    
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

void LaptopComputer::closeAllAndShutdown()
{
    std::cout << "Stopping all processes...\n";
    int processesToClose = operatingSystem.numActiveProcesses;

    for (int i = 1; i <= processesToClose; ++i)
    {
        operatingSystem.numActiveProcesses--;
        if (i % 50 == 0 || i == processesToClose)
        {
            std::cout << "Stopped " << i << " of " << processesToClose << "...\n";
        }
    }
    std::cout << "All processes stopped, shutting down.\n";
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

void printDivider(int numToPrint = 1)
{
    for (int i = 0; i < numToPrint; ++i)
    {
        std::cout << "-----------------------------------------------\n"; 
    }
}

#include <iostream>
int main()
{
    Example::main();
    
    /*
     Part3-3: UDT instantiations
    */
    BurgerShack firstBurgerShack;
    BurgerShack secondBurgerShack;

    FishingTrawler trawler1;
    FishingTrawler trawler2;

    Dog percy;
    Dog leon;

    SteamLocomotive transCanada;
    SteamLocomotive localService;

    Screen laptopDisplay;
    Screen secondMonitor;

    Keyboard laptopKeyboard;
    Keyboard externalKeyboard;

    HardDrive primaryHardDrive;
    HardDrive backupDrive1;

    RAM eightGigs;
    RAM sixteenGigs;

    OperatingSystem linuxManjaro;
    OperatingSystem windows10;

    LaptopComputer macbookPro;
    LaptopComputer chromebook;

    /*
     Part 3-4: calling member functions
    */
    std::cout << "PART 3-4\n";
    firstBurgerShack.cleanGrill(true);
    printDivider();
    trawler1.pullInNet(4);
    printDivider();
    leon.goToSleep(true);
    printDivider();
    localService.addCoalToFurnace(32.3f);
    printDivider();
    laptopDisplay.adjustBrightness(400);
    printDivider();
    externalKeyboard.triggerFunctionKeyAction(127);
    printDivider();
    primaryHardDrive.partitionHardDrive(10000);
    printDivider();
    sixteenGigs.loadIntoActiveMemory(42330, 45000);
    printDivider();
    linuxManjaro.updateOperatingSystemVersion(true);
    printDivider();
    macbookPro.openApplication(4);
    printDivider(2);

    /*
     Part 3-5: print member variables/return values
    */
    std::cout << "PART 3-5\n";
    std::cout << "The first burger shack serves " << firstBurgerShack.numBurgersServedPerDay << " burgers each day.\n"; 
    printDivider();
    std::cout << "The second trawler has " << trawler2.amountOfGasRemaining << " gallons of fuel remaining.\n";
    printDivider();
    std::cout << "Leon has a top speed of " << leon.topSpeed << " km/hr.\n";
    printDivider(); 
    std::cout << "The Local Service is " << localService.age << " years old.\n";
    printDivider();
    std::cout << "Working: " << laptopDisplay.screenImage.getRedLevelOfTriad(2300, 124) << " was the value.\n";
    printDivider();
    std::cout << "The external keyboard has " << externalKeyboard.numKeys << " keys.\n";
    printDivider();
    std::cout << "Working: " << primaryHardDrive.retrieveDataFromDisk(42032).getRelativePath() << " is the filename\n";
    printDivider();
    std::cout << "Is the example block of memory currently being accessed? " << (sixteenGigs.exampleMemoryBlock.currentlyBeingAccessed ? "-YES" : "-NO") << "\n";
    printDivider();
    std::cout << "Working: " << macbookPro.searchForWifiNetworks(false) << " was the network returned.\n";
    printDivider();
    std::cout << "The latency of the keyboard is " << macbookPro.keyboard.latency << "ms.\n";
    printDivider(2);
    
    std::cout << "PART 5-4\n";

    /*
     PART 5-3&4: calls to looping member functions
    */
    std::cout << "Is it time to clean the grease trap?\n" << (firstBurgerShack.isItTimeToCleanTheGreaseTrap(6, 5) ? "YES" : "NO") << ": it has been " << firstBurgerShack.daysSinceGreaseTrapCleaned << " days.\n";
    printDivider();
    trawler2.setSailForNumDays(5);
    std::cout << "Fuel remaining: " << trawler2.amountOfGasRemaining << " gallons.\n";
    printDivider();
    percy.doSomeTricks(3);
    std::cout << "The dog's owner " << (percy.ownerNancy.hasDogTreats ? "HAS a few" : "DOES NOT have any") << " more dog treats.\n";
    printDivider();
    localService.removeCarsFromTrain(5);
    std::cout << "There are " << localService.numCarsOnTrain << " cars on this train.\n";
    printDivider();
    auto returnedPixelMap = laptopDisplay.getNewPixelMapToDraw(3, 5, "Green");
    std::cout << "X: " << returnedPixelMap.numPixelsX << "px     Y: " << returnedPixelMap.numPixelsY << "px\n";
    printDivider();
    laptopKeyboard.adjustBacklightingBrightness(-6);
    printDivider();
    backupDrive1.formatHardDrive();
    std::cout << "Currently used disk space: " << backupDrive1.currentlyUsedDiskSpace << "gb.\n";
    printDivider();
    sixteenGigs.overclockRAM(2500);
    std::cout << (sixteenGigs.exampleMemoryBlock.overheating ? "Needs to cool down..." : "Good to go") << std::endl;
    printDivider();
    windows10.parseActiveProcesses(150);
    printDivider();
    macbookPro.closeAllAndShutdown();
    std::cout << macbookPro.operatingSystem.numActiveProcesses << " active processes.\n";
    printDivider();

    std::cout << "good to go!" << std::endl;
}
