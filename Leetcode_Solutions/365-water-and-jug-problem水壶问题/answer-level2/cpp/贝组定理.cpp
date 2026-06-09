### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        if(x == 0 || y == 0) return x + y == z || z == 0;
        return z % gcd(x,y) == 0;
    }
};
```