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


int TIME;
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
 *
 */
void updateStats()
{
    
}


int main() {
    ifstream input;
    string line;
    
    vector<plane> arriving;
    vector<plane> departing;
    
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


