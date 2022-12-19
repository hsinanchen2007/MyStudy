### 解题思路
裴蜀定理：x y 均不为零，则存在 a b 满足等式 ax + by = gcd(x,y)
并且可证：gcd(x,y) 是满足条件的最小正整数值，即(z % gcd(x,y)==0)时才存在 a b 解
需要注意：x y 均不能为零，且本题中两个水壶最多用一次，需要额外判定 (x + y >= z)

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x==0&&y==0) return z==0;
        else if (x==0) return z%y==0;
        else if (y==0) return z%x==0;
        else return x + y >= z && z % gcd(x,y) == 0;
    }
};
```