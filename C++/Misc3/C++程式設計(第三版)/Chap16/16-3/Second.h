// Second.h
// --------------------------------------
#ifndef SECOND_H
#define SECOND_H
namespace NS2   // 宣告名稱空間 NS2
{
  const double Gain = 2.6;
  struct Member
   {
    int     IdNum;
    char    Name[20];
    double  Profit;
   };
  double Fnc(double);
}
#endif