### 解题思路
dp[i]表示i的最大子段乘积
dp[i]依赖前置的每个状态dp[j] (1 <= j < i)
从dp[j]转移到dp[i]又有两种状态，j要么分割，要么不分割。其中dp[j]存放分割情况下的最大值，而j刚好为不分割的值。
因此dp[i]从dp[j]转移过来的方程为 dp[i] = max(dp[j], j) * (i-j);

i前面所有的j都转移过来的最大值  dp[i] = max(dp[i], max(j, dp[j])*(i-j));

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = i-1; j >= 1; --j) {
                dp[i] = max(dp[i], max(j,dp[j])*(i-j));
            }
        }
        return dp[n];
    }
};
```