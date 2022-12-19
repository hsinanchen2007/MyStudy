## 思路一：二进制
比如指数为18，二进制表示为10010，即1 * 2^4 + 0 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0，而x^18 = x ^ (2^4+2^1)，即将对应1的位置权重相加，系数可以通过0和1可以通过右移指数得到，幂次可以通过不断累乘得到。
**注意点**：指数为负数最小值-2147483648时，考虑用长整型保存。

### 代码
```c++
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long p = n;
        if (p < 0) {
            x = 1/x;
            p = -p;
        } 
        while (p) {
            if (p & 1 == 1) {
                res *= x;
            }
            x *= x;                            
            p = (p >> 1);
        }
        return res;
    }
};
```

## 思路二：递归
如果指数是偶数，则可以利用x^n = x^(n/2) * x^(n/2)；如果指数是奇数，则x^n = x^(n-1)/2 * x^(n-1)/2。

![16_Power.PNG](https://pic.leetcode-cn.com/cc8bfa61f4701b7720ad9d9e9eab469759f351bd21585bdba0a1f19219e89441-16_Power.PNG)

### 代码
```c++
class Solution {
public:
    double myPow(double x, int n) {
        long long int p = n;
        if (p < 0) {
            x = 1/x;
            p = -p;
        } 
        double res = fun(x, p);        
        return res;
    }
    double fun(double x, long long int n) {
        if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }
        double res = fun(x, n >> 1);
        res *= res;
        if (n & 1 == 1) {
            res *= x;
        }
        return res;
    }
};
```

