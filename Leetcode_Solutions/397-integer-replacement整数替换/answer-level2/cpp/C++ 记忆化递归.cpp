```
class Solution {
public:
    unordered_map<int, int> memo;
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n == INT_MAX) return 32;
        if (memo.count(n)) return memo[n];
        int res = 0;
        if (n & 1) {
            res = 1 + min(integerReplacement(n - 1), integerReplacement(n + 1));
        } else {
            res = 1 + integerReplacement(n >> 1);
        }
        memo[n] = res;
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/8b6741660653045d884e89b9db6cc9c64ffae436d0f8017aa87a8350c3a5d63a-image.png)
