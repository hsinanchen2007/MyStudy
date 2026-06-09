### 先对于大于9 的数循环取余，得到num，此过程中若num为0，则判定为9的倍数。在100以内的9的倍数，个十位相加计算num结果都是9。而当num< 9时，直接输出。

### 代码

```cpp
class Solution {
public:
    int addDigits(int num);
     
};

int Solution::addDigits(int num)
{
   if(num>9)
    {num=num%9;
    if(num == 0)
      return 9;
    }
  return num;
   
}
```