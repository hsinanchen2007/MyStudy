// TimeTest.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
// ---- 主程式 ----------------------------------
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
	cout << "CLOCKS_PER_SEC 是: \n" <<  CLOCKS_PER_SEC  << endl;			
	cout << "運算 " << NumCycle << " 次所花費的時間是: \n"
            << Duration << " 秒."  << endl;  
	cout << "每次運算所花費的時間是: \n"
            << setiosflags(ios::scientific)
            << Duration / double(NumCycle)
            << " 秒."  << endl;
	system("pause");
	return 0;
}
