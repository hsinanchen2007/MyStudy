### 解题思路
首先假设两个杯子能够量出z升水（不要求精确），那么就会有等式ax+by=z(1)成立（a>=0,b>=0）
令g为x,y的最大公约数，则x=c1*g,y=c2*g(2)(c1,c2为正整数);
将(2)带入(1)中,得：
                         (a*c1+b*c2)*g=z;
因为要求准确地量出z,则(a*c1+b*c2)也为正整数，因此z就为g的倍数。

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
       
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        return z % gcd(x, y) == 0;
    

    }
};
```