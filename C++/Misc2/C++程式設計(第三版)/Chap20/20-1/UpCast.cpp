// Upcast.cpp
// -----------------------------------------------
#include <iostream>
using namespace std;

//---- �ŧi���O Shape ----------------------------
class Shape
{ 
	private:
		int i;
	public:
		Shape(): i(7){}
		~Shape(){}
		virtual void Draw()  {cout<<" �e�ӹ�.\n";}
		virtual void Area()  {cout<<" �Ϫ����n.\n";}
		virtual void Erase() {cout<<" �N�ϲM��.\n";}
		void ObjectSize()    { Area();}
};

//---- �ŧi���O Circle ---------------------------
class Circle : public Shape
{ 
	private:
		int r;
	public:
		Circle(): r(5)      {}
		Circle(int N): r(N) {}
		~Circle()           {}
		void Draw()  {cout<<" �e�@�Ӷ��.\n";}
		void Area()  {cout<<" ��Ϊ����n�� PI*R*R.\n";}
		void Erase() {cout<<" ���βM��.\n";}
};

void Remove(Shape& S1) {S1.Erase();}

// ---- �D�{�� -----------------------------------
int main()
{
	Circle C2;
	Shape* pS;

	pS = &C2;

	cout << "<1> ����upS->Draw();�v����:" << endl;
	pS->Draw();

	cout << "<2> ����upS->ObjectSize();�v����:" << endl;
	pS->ObjectSize();

	cout << "<3> ����uRemove(C2);�v����:" << endl;
	Remove(C2);

	system("pause");
	return 0;
}
