//檔案名稱：d:\C++16\C1604.cpp
#include <iostream>
using namespace std;

#define MAX 80

class Stack	//自定Stack資料類別
{
	int st[MAX];
	int top;
public:
	class Full	//Full錯誤處理類別
	{
	};
	class Empty	//Empty錯誤處理類別
	{
	};
	Stack()		//建立者函數
	{
		top = -1;	//堆疊指標起始值
	}
	void push(int i)	//資料推入堆疊函數
	{
		if(top >= MAX - 1)	//若top大於等於堆疊上限
			throw Full();	//投擲例外並傳遞Full()
		st[++top] = i;	//堆疊指標加1
	}
	int pop()	//取出堆疊資料函數
	{
		if(top < 0)	//若top小於堆疊下限
			throw Empty();	//投擲例外並傳遞Empty()
		return st[top--];	//堆疊指標減1
	}
};

int main(int argc, char** argv)
{
	Stack s;
	try {
		s.push(10);	//top=0; st[0]=10;
		s.push(40);	//top=1; st[1]=40;
		cout << s.pop() << endl;	//傳回st[1]=40; top=0
		cout << s.pop() << endl;	//傳回st[0]=10; top=-1
		cout << s.pop() << endl;	//top<0; throw Empty()
	}
	catch(Stack::Full) {
		cout << "堆疊滿了！\n";
	}
	catch(Stack::Empty)	{
		cout << "堆疊空了！\n";
	}
	return 0;
}
