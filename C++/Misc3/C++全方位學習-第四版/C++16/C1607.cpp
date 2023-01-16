//檔案名稱：d:\C++16\C1607.cpp
#include <iostream>
#include <string>
using namespace std;

#define max 10	//設定堆疊最大空間

template <class TYPE> class Stack	//定義 Stack 類別範本
{
	TYPE st[max];	//堆疊空間
	int ptr;		//堆疊指標
public:
	Stack() {ptr = 0;}
	void push(TYPE obj);	//宣告推入資料函數原型
	TYPE pop();	//宣告取回資料函數原型
};

template <class TYPE> void Stack<TYPE>::push(TYPE obj)
{					//定義推入資料函數
	string error = "堆疊滿了！\n";
	if(ptr==max) {
		throw error;
	}
	st[ptr] = obj;	//推入資料
	ptr++;		//指標加 1
}

template <class TYPE> TYPE Stack<TYPE>::pop()
{					//定義取回資料函數
	string error = "堆疊空了！\n";
	if(ptr==0) {
		throw error;
	}
	ptr--;		//指標減 1
	return st[ptr];	//傳回資料
}

int main(int argc, char** argv)
{
	int i;
	try {
		Stack<int> iStack;	//建立整數堆疊
		Stack<char> cStack;	//建立字串堆疊
		iStack.push(10);	//推入整數堆疊
		cStack.push('a');	//推入字串堆疊
		iStack.push(20);	//推入整數堆疊
		cStack.push('b');	//推入字串堆疊
		iStack.push(30);	//推入整數堆疊
		cStack.push('c');	//推入字串堆疊

		for(i=2; i>=0; i--)	//從整數堆疊取回
			cout << "iStack[" << i << "] = " << iStack.pop() << '\t';
		cout << endl;

		for(i=2; i>=0; i--)	//從字串堆疊取回
			cout << "cStack[" << i << "] = " << cStack.pop() << '\t';
		cout << endl;
	} catch(string str) {
		cout << str;
	}
	return 0;
}
