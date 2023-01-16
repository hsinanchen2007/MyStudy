// Test.cpp
// --------------------------------------
#include <iostream>
using namespace std;
#include "First.h"
//#include "Second.h"

// -----------------------------------
int main()
{
	Member Ma={"George Wang", 23246352};
	Member Mb={"Peter White", 34536767};
	cout << "Name of Ma is         "
		<< Ma.Name  << endl;
	cout << "Phone number of Mb is "
		<< Mb.Phone << endl;
	system("PAUSE");
	return 0;
}