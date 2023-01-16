// Test.cpp
// --------------------------------------
#include <iostream>
using namespace std;

#include "First.h"
// 名稱空間 NS1 的 using 指令
using namespace NS1;  

// ----主程式-----------------------
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