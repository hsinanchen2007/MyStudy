// Format_3.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
// --- ¥Dµ{¦¡  --------------------------------
int main()
{
  double t1=253.0;
  double t2=0.123456789;

    cout << " (1)The value of t1 is :  "
            << t1 << endl;
    cout << " (2)The value of t1 is :  "
            << std::setprecision(2)
            << t1 << endl;
    cout << " (3)The value of t1 is :  "
            << std::setprecision(5)
            << t1 << endl;
    cout << " (4)The value of t1 is :  "
            << std::setprecision(2)
            << std::showpoint << t1 << endl;
    cout << " (5)The value of t1 is :  "
            << std::setprecision(5)
            << std::showpoint << t1 << endl;
    cout << " (6)The value of t1 is :  "
            << std::setprecision(2)
            << std::showpoint << std::fixed << t1 << endl;
    cout << " (7)The value of t1 is :  "
            << std::setprecision(5)
            << std::showpoint << std::fixed << t1 << endl;
    cout << " (8)The value of t1 is :  "
            << std::setprecision(2)
            << std::showpoint << std::scientific << t1 << endl;
    cout << " (9)The value of t1 is :  "
            << std::setprecision(5)
            << std::showpoint << std::scientific << t1 << endl;
    cout << "(10)The value of t2 is :  "
            << t2 << endl;
    cout << "(11)The value of t2 is :  "
            << std::setprecision(2)
            << t2 << endl;
    cout << "(12)The value of t2 is :  "
            << std::setprecision(5)
            << t2 << endl;
    cout << "(13)The value of t2 is :  "
            << std::setprecision(2)
            << std::showpoint
            << t2 << endl;
    cout << "(14)The value of t2 is :  "
            << std::setprecision(5)
            << std::showpoint << t2 << endl;
    cout << "(15)The value of t2 is :  "
            << std::setprecision(2)
            << std::showpoint << std::fixed << t2 << endl;
    cout << "(16)The value of t2 is :  "
            << std::setprecision(5)
            << std::showpoint << std::fixed << t2 << endl;
    cout << "(17)The value of t2 is :  "
            << std::setprecision(2)
            << std::showpoint << std::scientific << t2 << endl;
    cout << "(18)The value of t2 is :  "
            << std::setprecision(5)
            << std::showpoint << std::scientific << t2 << endl;
    cout << std::hex << 26;
	system("PAUSE");
    return 0;
}