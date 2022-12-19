### 解题思路
此处撰写解题思路

### 代码

```c
#include <math.h>
#define False 0
#define True  1

bool judgeSquareSum(int c){
    int i = 0;
    double value = 0;
    int count =  sqrt(c);
    for(i = 0;i <= count;i++)
    {
      value = sqrt(c - i*i);
      if((value- (int)value) == 0)
      {
          return True;
      }

    }
    return False;
}





```
1、首先领用math数学库sqrt函数求平方根，让遍历的范围缩小
2、巧妙运用浮点数取整来判断是否整除