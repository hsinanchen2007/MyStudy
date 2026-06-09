### 解题思路
状态：柱子

dp数组含义：dp[i]表示前i个最多方案数

方程：$dp[i] = dp[i-1]\times (k-1)+dp[i-2]\times (k-1),i > 2$

Base case: $dp[0] = 0, dp[1] = k, dp[2] = k\times k$

### 代码

```cpp
class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0) return 0;
        if(n == 1) return k;
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = k, dp[2] = k*k;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] * (k - 1) + dp[i - 2] * (k - 1);
        }
        return dp[n];
    }
};
```