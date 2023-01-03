// ElevatorClass.h
// --------------------------------------
#ifndef ELEVATORCLASS_H
#define ELEVATORCLASS_H

#include <iostream>
using namespace::std;

//---- 摸 Elevator--------
class Elevator
{ 
	private:    
		int  CurrentFloor;    
		void Move(int);
	public:
		Elevator(); // 箇砞篶ㄧ计
		Elevator(int); // 篶ㄧ计(砞﹚)
		~Elevator();  // 秆篶ㄧ计
		void Call(int);
		void Select(int);
		static int Count; // static 跑计
};

#endif