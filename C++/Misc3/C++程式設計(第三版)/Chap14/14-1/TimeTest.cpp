// TimeTest.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
// ---- �D�{�� ----------------------------------
int main()
{
	clock_t Start, Finish;
	double x = 8745.87, y;
	double Duration;
	int NumCycle=1000000;
	Start=clock();
  
	for (int i=0; i<NumCycle; i++)
		y = sqrt(x);	
  
	Finish=clock();

	cout << setiosflags(ios::fixed) << setiosflags(ios::right) 
			<< setiosflags(ios::showpoint) << setprecision(7);
	cout << " y = " << setw(10) << y << endl;
	Duration = double(Finish-Start)/CLOCKS_PER_SEC;
	cout << "CLOCKS_PER_SEC �O: \n" <<  CLOCKS_PER_SEC  << endl;			
	cout << "�B�� " << NumCycle << " ���Ҫ�O���ɶ��O: \n"
            << Duration << " ��."  << endl;  
	cout << "�C���B��Ҫ�O���ɶ��O: \n"
            << setiosflags(ios::scientific)
            << Duration / double(NumCycle)
            << " ��."  << endl;
	system("pause");
	return 0;
}
