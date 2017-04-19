#include <fstream>
#include <iostream>
#include <string> 
#include <list>
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
		input.open("PATH TO YOUR FILE", ios::in);//you need a path to your file here
		while (!input.eof())
		{
			getline(input, line, ','); //this will read the contents between commas one at a time
			                           //so underneath you can one at a time place information into their locations in the structure
		}
		input.close();
	

}

