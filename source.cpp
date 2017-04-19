#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

struct plane {
    struct plane *before;
    struct plane *after;
    int sched_time;
    int actual_time;
    int fuel;
    int passengers;
    int cargo;
    bool Fam;
    bool successful;
} *Arrival, *departure;


int TIME; // The real time

list<plane> arriving;
list<plane> departing;
list<plane> crashed; // we may consider having this

int takeOffWaitTime;
int landingWaitTime;
int numCrash;
int numDeparting;
int numArriving;
int numPeopleSafe;
int numPeopleKilled;
int numGrandKilled;
int waitTimeGrand;
int numCargoSafe;
int cargoDestroyed;

// declare methods
void next();
void adjustFuel();
void processPlanes();
void sortPlanes();
void printStats();
void updateStats();



/*
 *  This can be a function that increments the time.  Here, we would
 *  update fuel, time, vectors, etc.  We can call other methods like
 *  a sort function or a updateStats function.  Each turn, it will
 *  delete two plane structs.  
 *
 *  In order to determine how many planes can depart, we need to consider
 *  out how many planes are arriving.  If 7 planes with the same amount
 *  of fuel are arriving in 5 time units, we will need to land at least
 *  two planes immediately.
 *
 *
 */
void next()
{
    processPlanes(); //calling this method before adjusting fuel will save more planes(I think)
    adjustFuel();
    
    TIME++;
}

/*
 *  Function that decrements the fuel in each plane, and refuels 
 *  departing planes when necessary.
 */
void adjustFuel()
{
    for(plane p_d: departing) {
        p_d.fuel--;
        if(p_d.fuel < 20) {
            p_d.fuel += 10;
            p_d.actual_time += 10;
        }
    }
    
    for(plane p_a: arriving) {
        p_a.fuel--;
    }
}

/*
 *  Processes two planes, and crashed planes.
 *  Updates crashed stats
 */
void processPlanes()
{
    // process two planes
    // ...
    
    
    //process crashed planes
    for(plane p_a: arriving) {
        if(p_a.fuel == -1) {
            numCrash++;
            numPeopleKilled += p_a.passengers;
            if(p_a.Fam) {
                numGrandKilled++;
            }
            cargoDestroyed += p_a.cargo;
            
            
        }
    }
}

/*
 *  Sorts the planes into a queue(the first plane will be the next to
 *  arrive or depart).  Prioritizes grandchildren, passengers, cargo, 
 *  and wait time.
 */
void sortPlanes()
{
    
}

/*
    •Average Take off wait time
    •Average landing wait time 
    •Number of plan crash 
    •Number of plans departing
    •Number of planes arriving
    •Number of people that landed safely 
    •Number of people killed
    •Number of Grandchildren killed 
    •Average wait time for a grandchild  Arriving or departing.  (Dead grandchildren not included)
    •Amount of cargo that landed safely
    •Amount of destroyed Cargo 
    •Amount of time it takes to process a input file
 */
void printStats()
{
    cout << "Average Take off wait time: " << endl;
    cout << "Average landing wait time: " << endl;
    cout << "Number of plan crash: " << endl;
    cout << "Number of plans departing: " << endl;
    cout << "Number of planes arriving: " << endl;
    cout << "Number of people that landed safely: " << endl;
    cout << "Number of people killed: " << endl;
    cout << "Number of Grandchildren killed: " << endl;
    cout << "Average wait time for a grandchild  Arriving or departing.  (Dead grandchildren not included): " << endl;
    cout << "Amount of cargo that landed safely: " << endl;
    cout << "Amount of destroyed Cargo: " << endl;
    cout << "Amount of time it takes to process a input file: " << endl;
}


/*
 *  Updates non-crashed stats
 */
void updateStats()
{
    for(plane p_a: arriving) {
        
    }
    
    for(plane p_d: departing) {
        
    }
}


int main() {
    ifstream input;
    string line;
    
    
    
    input.open("/Users/erniedefoy/Desktop/planes.txt", ios::in);//you need a path to your file here
    
    //while (!input.eof())
    while(input.good())
    {
        //getline(input, line, ','); //this will read the contents between commas one at a time
        //so underneath you can one at a time place information into their locations in the structure
        
        getline(input, line, ',');
        
        if(line == "D") {
            plane p = plane();
            
            getline(input, line, ',');
            p.sched_time = std::stoi(line);
            
            getline(input, line, ',');
            string a_or_d = line;
            
            getline(input, line, ',');
            p.fuel = std::stoi(line);
            
            getline(input, line, ',');
            p.passengers = std::stoi(line);
            
            getline(input, line, ',');
            p.cargo = std::stoi(line);
            
            getline(input, line);
            line == "Y" ? p.Fam = true : p.Fam = false;
            
            a_or_d == "A" ? arriving.push_back(p) : departing.push_back(p);
        }
        else {
            // Print Statistics or wait
        }
        
    }
    
    
    /*
    for(plane pl: arriving) {
        cout << "hi"; //test prints "hi" for each arriving plane
    }
    */
     
    input.close();
    
    cout << endl;
    
}


