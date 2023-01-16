//�ɮצW�١Gd:\C++16\C1607.cpp
#include <iostream>
#include <string>
using namespace std;

#define max 10	//�]�w���|�̤j�Ŷ�

template <class TYPE> class Stack	//�w�q Stack ���O�d��
{
	TYPE st[max];	//���|�Ŷ�
	int ptr;		//���|����
public:
	Stack() {ptr = 0;}
	void push(TYPE obj);	//�ŧi���J��ƨ�ƭ쫬
	TYPE pop();	//�ŧi���^��ƨ�ƭ쫬
};

template <class TYPE> void Stack<TYPE>::push(TYPE obj)
{					//�w�q���J��ƨ��
	string error = "���|���F�I\n";
	if(ptr==max) {
		throw error;
	}
	st[ptr] = obj;	//���J���
	ptr++;		//���Х[ 1
}

template <class TYPE> TYPE Stack<TYPE>::pop()
{					//�w�q���^��ƨ��
	string error = "���|�ŤF�I\n";
	if(ptr==0) {
		throw error;
	}
	ptr--;		//���д� 1
	return st[ptr];	//�Ǧ^���
}

int main(int argc, char** argv)
{
	int i;
	try {
		Stack<int> iStack;	//�إ߾�ư��|
		Stack<char> cStack;	//�إߦr����|
		iStack.push(10);	//���J��ư��|
		cStack.push('a');	//���J�r����|
		iStack.push(20);	//���J��ư��|
		cStack.push('b');	//���J�r����|
		iStack.push(30);	//���J��ư��|
		cStack.push('c');	//���J�r����|

		for(i=2; i>=0; i--)	//�q��ư��|���^
			cout << "iStack[" << i << "] = " << iStack.pop() << '\t';
		cout << endl;

		for(i=2; i>=0; i--)	//�q�r����|���^
			cout << "cStack[" << i << "] = " << cStack.pop() << '\t';
		cout << endl;
	} catch(string str) {
		cout << str;
	}
	return 0;
}
