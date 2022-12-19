依次按照个位，十位，百位的顺序得到罗马数字，最后将几个罗马数字进行拼接得到结果

class Solution {
public:
  string intToRoman(int num) {
  int gewei=num%10;
  int shiwei=num%100-num%10;
  int baiwei=num%1000-num%100;
  int qianwei=num%10000-num%1000;
  //个位数
  string a;
  if (gewei==4) a="IV";
  else if (gewei==9) a="IX";
  else if(gewei<5) 
  {a="";
   for(int i=0;i<gewei;i++)
   a+='I';
  }
  else if(gewei<10)
  {
  a="V";
  for(int i=0;i<gewei-5;i++)
  a+='I';
  } 
 
 //十位数
string b;

if (shiwei==40) b="XL";
  else if (shiwei==90) b="XC";
  else if(shiwei<50) 
  {b="";
   for(int i=0;i<shiwei;i+=10)
   b+='X';
  }
  else if(shiwei<100)
  {
  b="L";
  for(int i=0;i<shiwei-50;i+=10)
  b+='X';
  } 

//百位数
string c;

if (baiwei==400) c="CD";
  else if (baiwei==900) c="CM";
  else if(baiwei<500) 
  {c="";
   for(int i=0;i<baiwei;i+=100)
   c+='C';
  }
  else if(baiwei<1000)
  {
  c='D';
  for(int i=0;i<baiwei-500;i+=100)
  c+='C';
  } 

//千位数
string d="";
for(int i=0;i<qianwei;i+=1000)
d+='M';




return d+c+b+a;
    }
};