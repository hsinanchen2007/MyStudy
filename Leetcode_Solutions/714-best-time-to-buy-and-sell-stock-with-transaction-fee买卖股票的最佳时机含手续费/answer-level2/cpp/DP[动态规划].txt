### 解题思路
1、设置dp： 
dp[i][0] : 第i天，不持有股票时的收益
dp[i][1] : 第i天，持有股票时的收益
2、获取状态转移矩阵：
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - nums[i] - fee)
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + nums[i])
3、初始状态设定：
dp[0][0]: 表示第0天，不持有股票时的收益 == 0;
dp[0][1]: 表示第0天，持有股票的收益(不可能存在的现象：INT_MIN);
4、求解DP，返回值.
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty() || prices.size() == 0) {
            return 0;
        }
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - nums[i] - fee)
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + nums[i])
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        for (int i = 1; i < dp.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1] - fee);
        }
        return dp[prices.size()][0];
    }
};
```