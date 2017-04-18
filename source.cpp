/******************************************************


//test
 sgadhsdhsdh



********************************************************/

#include <iostream>
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

}
