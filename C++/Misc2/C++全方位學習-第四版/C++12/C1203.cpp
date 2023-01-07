//郎嘿d:\C++12\C1203.cpp
#include <cstdlib>
#include <iostream>
using namespace std;

class Timer
{
	int seconds;
public:
	Timer() {		//﹚竡礚把计ミ
		seconds = 0;
	}
	Timer(int s) {	//﹚竡俱计把计ミ
		seconds = s;
	}
	Timer(char *t) {	//﹚竡夹把计ミ
		seconds = atoi(t);
	}
	int getTime() {	//﹚竡眔secondsㄧ计
		return seconds;
	}
};

int main(int argc, char** argv)
{
	char str[20] = "250";
	Timer t1;		//t1.seconds = 0
	Timer t2(10);	//t2.seconds = 10
	Timer t3(str);	//t3.seconds = 250
	cout << "t1 = " << t1.getTime() << endl;	//块t1ン
	cout << "t2 = " << t2.getTime() << endl;	//块t2ン
	cout << "t3 = " << t3.getTime() << endl;	//块t3ン
	return 0;
}
