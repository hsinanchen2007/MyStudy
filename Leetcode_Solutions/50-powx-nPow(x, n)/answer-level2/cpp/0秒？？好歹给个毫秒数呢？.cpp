### 解题思路
整数快速幂，浮点数快速幂，没区别。

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double p = x;
        if (n < 0) p = 1/x;
        n = abs(n);
        double pow = 1;
        while (n > 0) {
            if (n & 1) {
                pow *= p;
            }

            n >>= 1;
            p *= p;
        }

        return pow;
    }
};
```