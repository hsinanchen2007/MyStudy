// ElevatorClass.h
// --------------------------------------
#ifndef ELEVATORCLASS_H
#define ELEVATORCLASS_H

#include <iostream>
using namespace::std;

//---- �ŧi���O Elevator--------
class Elevator
{ 
	private:    
		int  CurrentFloor;    
		void Move(int);
	public:
		Elevator(); // �w�]�غc���
		Elevator(int); // �غc���(�i�]�w���)
		~Elevator();  // �Ѻc���
		void Call(int);
		void Select(int);
		static int Count; // static �ܼ�
};

#endif