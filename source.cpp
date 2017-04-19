/******************************************************






********************************************************/

#include <iostream>
#include <fstream>
#include <list>
#include <string>

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

class linkedlist
{
public:                             //definitions for the various methods to be used with this class

	linkedlist()
	{
		Arrival = NULL;
		departure = NULL;
	}

};

int main() {
	string line;
	ifstream myfile("myfile.txt");
	if (myfile.eof())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	return 0;

}

void printStats()
{

}
