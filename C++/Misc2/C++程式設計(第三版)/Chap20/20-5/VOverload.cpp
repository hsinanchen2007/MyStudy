// VOverload.cpp
// --------------------------------------
#include <iostream>
using namespace std;

//---- �ŧi���O Shape --------
class Shape
{
	private:
		int i;
	public:
		Shape(): i(7){}
		~Shape(){}
		virtual void Rotate()   {cout<<"�N�ϰj�� \n";}
		virtual void Rotate(int N)
			{cout<<"�N�ϰj�� "<< N << " ���\n";}
		virtual void Erase()  {cout<<"�N�ϲM��\n";}
};

//---- �ŧi���O Circle--------
class Circle : public Shape
{
	private:
		int r;
	public:
		Circle(): r(5)      {}
		Circle(int N): r(N) {}
		~Circle()           {}
		void Rotate()  {cout<<"�N��ΰj��\n";}
		void Erase()   {cout<<"���βM�� \n";}
};

//---- �ŧi���O Cylinder--------
class Cylinder : public Circle
{
	private:
		int r, h;	
	public:
		Cylinder(): r(5), h(1)    {}
		Cylinder(int M, int N): r(M), h(N) {}
		~Cylinder()         {}
		void Rotate(){cout<<"�N��W�ΰj��\n";}
		void Erase() {cout<<"���W�βM�� \n";}
};

// ----�D�{��---------------------------
int main()
{
	Circle C1;
	Cylinder CyL;
	Shape *pS = &C1;
	Shape &S1 = CyL;
	cout << "�upS->Rotate()�v : ";
	pS->Rotate();
	cout << "�upS->Rotate(2)�v: ";
	pS->Rotate(2);
	cout << "�u S1.Rotate()�v : ";
	S1.Rotate();
	cout << "�u S1.Rotate(4)�v: ";
	S1.Rotate(4);

	system("pause");
	return 0;
}
