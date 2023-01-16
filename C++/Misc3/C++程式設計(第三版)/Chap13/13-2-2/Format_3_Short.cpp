// Format_3Short.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double t1=253.0;

    cout << " (1)The value of t1 is :  "
            << std::setprecision(2) << t1 << endl;
    cout << " (2)The value of t1 is :  "
            << std::setprecision(3)
            << std::showpoint << t1 << endl;
    cout << " (3)The value of t1 is :  "
            << std::setprecision(5) << std::showpoint
            << std::fixed << t1 << endl;
    cout << " (4)The value of t1 is :  "
            << std::setprecision(5) << std::showpoint
            << std::scientific << t1 << endl;
	system("PAUSE");
    return 0;
}