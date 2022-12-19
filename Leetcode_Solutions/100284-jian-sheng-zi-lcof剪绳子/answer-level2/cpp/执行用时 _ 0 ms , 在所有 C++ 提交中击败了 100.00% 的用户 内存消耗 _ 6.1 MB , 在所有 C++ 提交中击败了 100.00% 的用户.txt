### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        // int res = 0;
        if (n == 2) {
            return 1;
        }
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[j] * (i - j), dp[i]);
                dp[i] = max(dp[i], j * (i -j));
            }
        }
        return dp[n];
    }
};
```