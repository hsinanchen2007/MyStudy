### 解题思路
基于以下事实：
    对 x^n，
    若 n 为奇数，有 x^n = x * x^(n-1)
    若 n 为偶数，有 x^n = x^(n/2) * x^(n/2)

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double half = myPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        if (n > 0) return half * half * x;
        return half * half / x;
    }
};
```

```cpp
//迭代的解法
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) res *= x;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};
```