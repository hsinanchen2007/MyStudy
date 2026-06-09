### 解题思路
定义resolve函数，将传入的数%10 来取出个位数，再整除10消除个位数。

### 代码

```cpp
class Solution {
public:
  unsigned int resolve(int a)
{
    unsigned int numafter=0;
    while (a!=0)
    {
        numafter=numafter * 10 + a%10;
        a=a/10;
    }
    return numafter;
}
     bool isPalindrome(int x) {
         if (x<0) return false;
         else if(resolve(x)==x) return true;
         else return false;
    }

};
```