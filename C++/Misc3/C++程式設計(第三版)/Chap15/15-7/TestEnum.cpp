// TestEnum.cpp
// --------------------------------------
#include <iostream>
using namespace std;

enum Direction {Up, Down, Left, Right};

// -------- 主程式 ------------------------
int main()
{
	int N;
	cout << "請輸入期望的運動方向\n";
	cout << "(0=Up, 1=Down, 2=Left, 3=Right):\n";
	cin >> N;
	switch (N)
	{
	case Up:
		cout << "Moving Up!\n"; 
		break;
	case Down:
		cout << "Moving Down!\n"; 
		break;
	case Left:
		cout << "Moving Left!\n"; 
		break;
		case Right:	
		cout << "Moving Right!\n"; 
		break;
	default:
		cout << "Static\n";
  }
  system("pause");
  return 0;
}
