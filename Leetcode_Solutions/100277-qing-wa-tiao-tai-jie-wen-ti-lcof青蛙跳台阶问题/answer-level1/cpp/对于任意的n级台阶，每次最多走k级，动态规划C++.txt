### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        if (n == 0 || n == 1) return 1;
        int k = 2;
        int dp[n+1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= k; i++ ) dp[i] = 2*dp[i-1] % 1000000007;
        for (int i = k+1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i] = (dp[i] + dp[i-j]) % 1000000007;
            }
        }
        return dp[n];
    }
};
```