// TimeTest2.cpp
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
	double Ta, Tb;
	int M = 1000000;
	int N =  200000;
	// == 執行A =============
	Start=clock();  
	for (int i=0; i<M; i++)
		y = sqrt(x);	
	Finish=clock();
	Ta = double(Finish-Start)/CLOCKS_PER_SEC;
	// == 執行B =============
	Start=clock();  
	for (int i=0; i<N; i++)
		y = sqrt(x);  
	Finish=clock();
	Tb = double(Finish-Start)/CLOCKS_PER_SEC;
	cout << "y is: " << y << endl;
	cout << setiosflags(ios::fixed)
		    << setiosflags(ios::right)
		    << setiosflags(ios::showpoint)
		    << setprecision(7);
	cout << " Ta / M 是: \n"
		    << setiosflags(ios::scientific)
		    << Ta / double(M) << " 秒."  << endl;
	cout << " Tb / N 是: \n"
		    << setiosflags(ios::scientific)
		    <<  Tb / double(N) << " 秒."  << endl;
	cout << "每次運算所花費的時間是: \n"
		    << setiosflags(ios::scientific)
		    << (Ta-Tb) / double(M-N) << " 秒."  << endl;
	system("pause");
	return 0;
}
