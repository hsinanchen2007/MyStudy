// FEClass.h
// --------------------------------------
#ifndef FECLASS_H
#define FECLASS_H

#include <iostream>
using namespace::std;

//---- �ŧi���O Elevator--------
class Elevator
{ 
  friend void Call(Elevator&, int);
  friend void Select(Elevator&, int);
  public:    
    Elevator(); // �w�]�غc���
    Elevator(int); // �غc���(�i�]�w���)
    ~Elevator();  // �Ѻc���
    static int Count; // static �ܼ�
  private:    
    int  CurrentFloor;    
    void Move(int);
};

#endif