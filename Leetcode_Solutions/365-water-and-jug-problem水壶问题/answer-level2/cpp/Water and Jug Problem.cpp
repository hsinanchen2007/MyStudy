### 解题思路
Water and Jug Problem

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (z==0) return true;
        if (x == 0 || y == 0) return x + y == z;
        return z % gcd(x, y) == 0;
    }
};
```