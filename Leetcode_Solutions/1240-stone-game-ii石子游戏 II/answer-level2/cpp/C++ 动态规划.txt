# 思路：
1，`dp[i][j]` 代表当前还剩下`i`堆石头，M为`j`的情况下能获取到的最大重量
2，状态转移方程为：
`dp[i][j] = max{sums[N] - sums[i] - dp[i - k][max(k, j)]} (1 <= k <= 2 * j)`
`sums[N] - sums[i]`代表剩下`i`堆石头的总重量，若本次取`k`堆，那么下次取的时候`M`就变成了`max(k, j)`，
下次能获取到的最大值对应到dp的定义就是`dp[i - k][max(k, j)]`
由此可得上面的转移方程

```C++ []
class Solution {
public:
    // dp[i][j] = max{sums[N] - sums[i] - dp[i - k][max(k, j)]} (1 <= k <= 2 * j)
    int stoneGameII(vector<int>& piles) {
        int N = piles.size();
        vector<int> sums(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            sums[i + 1] = sums[i] + piles[i];
        }
        vector<vector<int> > dp(N + 1, vector<int>(N + 1, 0));
        for (int i = 0; i <= N; ++i) {
            for (int j = i; j <= N; ++j) {
                dp[i][j] = sums[N] - sums[N - i];
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                for (int k = 1; k <= 2 * j && k <= i; ++k) {
                    dp[i][j] = max(dp[i][j], sums[N] - sums[N - i] - dp[i - k][min(max(k, j), N)]);
                }
            }
        }
        return dp[N][1];
    }
};
```

![image.png](https://pic.leetcode-cn.com/7235838ff8307ab2d59300855d6f49e53f6e911929d6fd4b632ac81361898af0-image.png)
