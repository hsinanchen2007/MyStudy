由贝祖定理可得，当且仅当 z 是 x, y 的最大公约数的倍数时，ax+by=z 有解。因此我们只需要找到 x, y 的最大公约数并判断 z 是否是它的倍数即可。

gcd函数简介
最大公因数（英语：highest common factor，hcf）也称最大公约数（英语：greatest common divisor，gcd）是数学词汇，指能够整除多个整数的最大正整数。而多个整数不能都为零。例如8和12的最大公因数为4。

```
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        return z % gcd(x, y) == 0;
    }
};
```
    
