// Test.cpp
// --------------------------------------
#include <iostream>
using namespace std;

#include "First.h"
// �W�٪Ŷ� NS1 �� using ���O
using namespace NS1;  

// ----�D�{��-----------------------
int main()
{
	Member Ma={"George Wang", 23246352};
	Member Mb={"Peter White", 34536767};
	cout << "Name of Ma is         "
		    << Ma.Name  << endl;
	cout << "Phone number of Mb is "
		    << Mb.Phone << endl;;
	cout << "Gain is: "
		    << Gain     << endl;
	cout << "Fnc(2.5) is: "
		    << Fnc(2.5) << endl;
	system("PAUSE");
	return 0;
}