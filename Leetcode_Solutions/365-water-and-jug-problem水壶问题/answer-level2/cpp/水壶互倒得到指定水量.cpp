### 解题思路
贝祖定理--》把ax+by=z有解转换为z为x、y的最大公约数的倍数

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