### 解题思路
对于两个水壶x和y组成的系统，每一次的操作一定是1.倒入x；2.倒入y；3.倒出x；4.倒出y。因为向一个非满的壶倒入或把非满的壶倒出是没有意义的
从而得到表达式 a*x + b*y = z，其中a,b可以使负数，表示倒出。
裴蜀定理：上式有解当且仅当z是x，y最大公约数的倍数
直接套公式就可以了，另外注意限制条件x+y>=z

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z)
            return false;
        if(x == 0 || y == 0)
            return z == 0  || x+y==z;
        return z % gcd(x,y) == 0;
    }
};
```