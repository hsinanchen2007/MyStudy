### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int res = 0;
        // int n = prices.size();
        // if (n < 1) return res;
        // for (int i = 1; i < n; i++) {
        //     if (prices[i] > prices[i - 1]) res += (prices[i] - prices[i - 1]);
        // }
        // return res;

        // 通用解法
        // dp[i][k][0]表示第i天，进行k次交易，不持有股票的最大收益
        // dp[i][k][1]表示第i天，进行k次交易，持有股票的最大收益
        // 因此本题可以进行无数次交易，因此，可以将k省略
        // 表示为dp[i][0], dp[i][1]
        // 优化：只需要设置两个变量记录前一天持有和不持有的最大值可以将空间复杂度降下来
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = 1; i <= n; i++) {
            // 第0天不会持有股票
            if (i == 1) dp[i - 1][1] = INT_MIN;
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
        }

        return max(dp[n][1], dp[n][0]);
    }
};
```