位移，然后做减法求解

```
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long lldividend = abs((long)dividend);
        long long lldivisor = abs((long)divisor);
        long long multiple = 1;
        while (lldividend >= lldivisor << 1) {
            lldivisor <<= 1;
            multiple <<= 1;
        }
        long long res = 0;
        
        while(multiple > 0 && lldivisor > 0) {
            if (lldividend >= lldivisor) {
                lldividend -= lldivisor;
                res += multiple;
            }
            multiple >>= 1;
            lldivisor >>= 1;
        }
        if ((dividend ^ divisor) < 0) {
            res = - res;
        }
        if (res > INT_MAX || res < INT_MIN) {
            return INT_MAX;
        }
        return res;
    }
};
```