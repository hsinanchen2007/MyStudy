### 解题思路
递归很直接，可以缓存中间计算结果，避免重复计算。

### 代码

```cpp
class Solution {
public:
    //T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
    map<int, int> memo;
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (2 == n) return 1;
        if (!memo.count(n)) {
            memo[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        }
        return memo[n];
    }
};
```