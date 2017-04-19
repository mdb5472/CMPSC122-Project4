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
    
   
    
    for(plane pl: arriving) {
        cout << "hi"; //test prints "hi" for each arriving plane
    }
    
    input.close();
    
    cout << endl;
    
}

