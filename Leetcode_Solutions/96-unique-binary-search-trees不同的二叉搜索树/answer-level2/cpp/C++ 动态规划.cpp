```
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 2, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
```

![image.png](https://pic.leetcode-cn.com/1827b2585df7b522221bf72ca05ecdb90360cbdc28a18132a8d0490da73a9e8a-image.png)
