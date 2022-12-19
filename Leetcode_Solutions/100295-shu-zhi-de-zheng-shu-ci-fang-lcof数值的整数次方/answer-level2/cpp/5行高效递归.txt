在递归函数内部搞定 `n` 的溢出情况，省的它溢出。
```cpp
// 执行用时 :4 ms, 在所有 C++ 提交中击败了69.36%的用户
// 内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户

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