//�ɮצW�١Gd:\C++16\C1604.cpp
#include <iostream>
using namespace std;

#define MAX 80

class Stack	//�۩wStack������O
{
	int st[MAX];
	int top;
public:
	class Full	//Full���~�B�z���O
	{
	};
	class Empty	//Empty���~�B�z���O
	{
	};
	Stack()		//�إߪ̨��
	{
		top = -1;	//���|���а_�l��
	}
	void push(int i)	//��Ʊ��J���|���
	{
		if(top >= MAX - 1)	//�Ytop�j�󵥩���|�W��
			throw Full();	//���Y�ҥ~�öǻ�Full()
		st[++top] = i;	//���|���Х[1
	}
	int pop()	//���X���|��ƨ��
	{
		if(top < 0)	//�Ytop�p����|�U��
			throw Empty();	//���Y�ҥ~�öǻ�Empty()
		return st[top--];	//���|���д�1
	}
};

int main(int argc, char** argv)
{
	Stack s;
	try {
		s.push(10);	//top=0; st[0]=10;
		s.push(40);	//top=1; st[1]=40;
		cout << s.pop() << endl;	//�Ǧ^st[1]=40; top=0
		cout << s.pop() << endl;	//�Ǧ^st[0]=10; top=-1
		cout << s.pop() << endl;	//top<0; throw Empty()
	}
	catch(Stack::Full) {
		cout << "���|���F�I\n";
	}
	catch(Stack::Empty)	{
		cout << "���|�ŤF�I\n";
	}
	return 0;
}
