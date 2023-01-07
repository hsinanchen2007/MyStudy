//�ɮצW�١Gd:\C++12\C1203.cpp
#include <cstdlib>
#include <iostream>
using namespace std;

class Timer
{
	int seconds;
public:
	Timer() {		//�w�q�L�Ѽƫإߪ�
		seconds = 0;
	}
	Timer(int s) {	//�w�q��ưѼƫإߪ�
		seconds = s;
	}
	Timer(char *t) {	//�w�q���аѼƫإߪ�
		seconds = atoi(t);
	}
	int getTime() {	//�w�q���oseconds���
		return seconds;
	}
};

int main(int argc, char** argv)
{
	char str[20] = "250";
	Timer t1;		//t1.seconds = 0
	Timer t2(10);	//t2.seconds = 10
	Timer t3(str);	//t3.seconds = 250
	cout << "t1 = " << t1.getTime() << endl;	//��Xt1���󪺭�
	cout << "t2 = " << t2.getTime() << endl;	//��Xt2���󪺭�
	cout << "t3 = " << t3.getTime() << endl;	//��Xt3���󪺭�
	return 0;
}
