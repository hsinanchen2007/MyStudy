// TestHead.cpp
// --------------------------------------
#include <iostream>
using namespace std;

#include "First.h"
#include "Second.h"

// ----¥Dµ{¦¡----------------------
int main()
{
  NS1::Member Ma={"George Wang", 23246352};
  NS2::Member Mb={34,"Peter White", 12.67};
  cout << "Name of Ma is:  "
          << Ma.Name       << endl;
  cout << "Name of Mb is:  "
          << Mb.Name       << endl;;
  cout << "NS1::Gain is: "
          << NS1::Gain       << endl;
  cout << "NS2::Gain is: "
          << NS2::Gain       << endl;
  cout << "NS1::Fnc(2.5) is: "
          << NS1::Fnc(2.5) << endl;
  cout << "NS2::Fnc(2.5) is: "
          << NS2::Fnc(2.5) << endl;
  system("PAUSE");
  return 0;
}