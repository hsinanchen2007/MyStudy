### 思路
除法的商就是可以从被除数中减去除数的次数而不使其为负的次数。下以成倍次数增加除数并从被除数中减去已经增加的除数次数。比如15 / 3，首先从等于当前除数开始，如果除数左移一位（即增长一倍为6）小于被除数，则除数左移一位同时用变量p记录除数增长倍数，接着除数在左移一位（即增长一倍为12）小于被除数，则除数左移一位同时p记录除数增长倍数（p左移一位，即表示增长4倍），除数再左移一位（即增长为24）大于15，则停止内循环，然后从被除数中减去当前除数，同时将增长倍数4加到结果集中，再进行外循环（15 - 12 = 3 >= 3）,重复上述过程，当前可以继续左移一位，所以最终结果为3 + 1 = 4。

### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long m = labs(dividend), n = labs(divisor);
        int res = 0;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        if (n == 1) return sign == 1 ? m : -m;
        while (m >= n) {
            long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p; //已经增加的除数次数加到结果集中
            m -= t;   //从被除数中减去已经增加的除数次数之和
        }
        return sign == 1 ? res : -res;
    }
};
```