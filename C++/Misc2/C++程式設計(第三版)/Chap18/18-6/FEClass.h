// FEClass.h
// --------------------------------------
#ifndef FECLASS_H
#define FECLASS_H

#include <iostream>
using namespace::std;

//---- 摸 Elevator--------
class Elevator
{ 
  friend void Call(Elevator&, int);
  friend void Select(Elevator&, int);
  public:    
    Elevator(); // 箇砞篶ㄧ计
    Elevator(int); // 篶ㄧ计(砞﹚)
    ~Elevator();  // 秆篶ㄧ计
    static int Count; // static 跑计
  private:    
    int  CurrentFloor;    
    void Move(int);
};

#endif