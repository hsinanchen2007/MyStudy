// PolyPure.cpp
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
		virtual void Draw() =0;
		virtual void Erase()=0;
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
		void Draw()  {cout<<"�e�@�Ӷ��.\n";}
		void Erase() {cout<<"���βM��.\n";}
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
		void Draw()  {cout<<"�e�@�Ӷ�W��.\n";}
		void Erase() {cout<<"���W�βM��.\n";}
};

void Make(Shape &S1) {S1.Draw();}

// ----�D�{��---------------------------
int main()
{
	Circle   C1;
	Cylinder CyL;
	Shape    *pS;

	cout << "�uMake(C1))�v : ";
	Make(C1);
	cout << "�uMake(CyL))�v: ";
	Make(CyL);

	pS = &C1;
	cout << "����upS=&C1�v����," << endl;
	cout << "�upS->Erase()�v�����G�O: ";
	pS->Erase();

	pS = &CyL;
	cout << "����upS=&CyL�v����," << endl;
	cout << "�upS->Erase()�v�����G�O: ";
	pS->Erase();

	system("pause");
	return 0;
}
