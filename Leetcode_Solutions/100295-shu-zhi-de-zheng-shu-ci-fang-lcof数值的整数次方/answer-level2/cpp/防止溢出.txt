### 解题思路
当 n 为 INT_MIN 时， 如果取负号， 整型变量会溢出。可以先让其加上 1, 再取负号。

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        
        if(n < 0){
            int exp = n;
            if(n == INT_MIN)
                exp = n + 1; 
            double res = 1.0/powOfUnsign(x, -exp);
            if (n == INT_MIN)
                return res/x;
            else
                return res;
        }
        else
            return powOfUnsign(x, n);
    }

    double powOfUnsign(double x, int n){
        if(n == 1) return x;
        double t1 = powOfUnsign(x, n >> 1);
        t1 = t1 * t1;
        if((n & 0x1) == 1)
            return t1 * x;
        return t1;
    }
};
```