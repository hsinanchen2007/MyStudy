此处用到了前两天每日一题用过的gcd算法，算法的作用是求两个数的最大公约数，算法的过程类似于辗转相除法
解题原理：裴蜀定理          目标：ax+by=z

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) 
    {
        if(x + y < z)   return false;
        if(x + y == z || x==z || y==z)  return true;
        return z % gcd(x,y) == 0;
    }
    int gcd(int a,int b) 
    { 
        return !b ? a : gcd(b,a%b); 
    }
};
```

