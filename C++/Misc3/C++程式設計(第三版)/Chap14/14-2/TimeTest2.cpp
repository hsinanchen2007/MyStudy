// TimeTest2.cpp
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
	double Ta, Tb;
	int M = 1000000;
	int N =  200000;
	// == ����A =============
	Start=clock();  
	for (int i=0; i<M; i++)
		y = sqrt(x);	
	Finish=clock();
	Ta = double(Finish-Start)/CLOCKS_PER_SEC;
	// == ����B =============
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
	cout << " Ta / M �O: \n"
		    << setiosflags(ios::scientific)
		    << Ta / double(M) << " ��."  << endl;
	cout << " Tb / N �O: \n"
		    << setiosflags(ios::scientific)
		    <<  Tb / double(N) << " ��."  << endl;
	cout << "�C���B��Ҫ�O���ɶ��O: \n"
		    << setiosflags(ios::scientific)
		    << (Ta-Tb) / double(M-N) << " ��."  << endl;
	system("pause");
	return 0;
}
