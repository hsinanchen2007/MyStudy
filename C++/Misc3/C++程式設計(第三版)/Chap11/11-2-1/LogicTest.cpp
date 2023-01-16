// LogicTest.cpp
// --------------------------------------
#define AND &&
#define OR  ||
#define NOT  !
#include <iostream>
using namespace std;
// ------  ¥Dµ{¦¡  -------------------------------
int main()
{
	float t1,t2;
	t1=0.5;
	t2=t1*0.2;
	cout << "((t1> 0.8) AND (t2 <0.9) OR (t1>0.2))= " 
		    << ((t1> 0.8) AND(t2 <0.9) OR (t1>0.2))
		    << endl;
	cout << " NOT(t1 > t2) =  " 
		    << NOT(t1 > t2) << endl;
	system("PAUSE");
	return 0;
}