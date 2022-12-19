```
class Solution {
public:
    double myPow(double x, int n) { 
        if(n == 0) return 1;
        // 因为abs(INT_MIN) 比 INT_MAX 大1， 所以不能直接用 -n
        if(n == INT_MIN) {
            n = n >> 1;
            x = x * x;
        }
        // 如果是负数
        if(n < 0) {
            // n取反，x取倒
            n = -n;
            x = 1/x;
        }
        // 奇数则将乘数平方，乘的次数处以2，否则将得出的结果再乘 x
        return (n & 1) == 0 ? myPow(x * x, n >> 1) : x * myPow(x * x, n >> 1);
    }
};
```
