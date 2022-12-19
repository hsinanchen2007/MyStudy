### 解题思路
这里的每一梯的走法类似于斐波那契数列，所以 f(n)=f(n-1)+f(n-2);
大家可以看一下代码简答明了

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
        {
            return 0;
        }
          int a=0;
          int b=1;
      while(n)
      { 
        int temp=a+b;
        a=b;
        b=temp;
        n--;
      }
      return b;
    }
};
```