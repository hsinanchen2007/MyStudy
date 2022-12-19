### 解题思路
mark一下，题解都写的很好

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x+y<z) return false;
        if (x==0 || y==0) return z==0 || z==x+y;
        return z % gcd(x,y)==0;
    }
    int gcd(int x, int y){//求最大公约数的函数
        return y == 0 ? x : gcd(y, x % y);
    }
};
```