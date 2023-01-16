// Format_2.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << hex << '|' << 14 << '|' << endl;

	cout << scientific
		    << setprecision(2) << '|' << setw(5)
		    << 46218.542 << '|' << endl;

	cout << setprecision ( 4 )
		    << fixed << showpoint << '|' <<  setw(13)
		    << 64.7766 << '|' <<  endl ;
	system("PAUSE");
	return 0;
}