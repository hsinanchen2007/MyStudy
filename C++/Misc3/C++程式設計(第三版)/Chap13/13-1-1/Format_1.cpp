// Format_1.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout  << '|' << setw(2) << 3       << '|' << endl ;
	cout  << '|' << setw(5) << 158     << '|' << endl ;
	cout  << '|' << setw(5) << 69.72   << '|' << endl ;
	cout  << setiosflags(ios::left)
		     << '|' << setw(5)<< 876     << '|' << endl ;
	cout  << setiosflags(ios::fixed)
		     << setprecision(2)
		     << '|' << setw(6) << 133.456 << '|' << endl ;
	system("PAUSE");
	return 0;
}