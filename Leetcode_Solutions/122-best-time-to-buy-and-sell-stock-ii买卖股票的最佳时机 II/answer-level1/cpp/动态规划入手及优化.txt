1. 状态定义
- 定义dp[i][0]表示第i天持有股票所能拥有的最大利润
- 定义dp[i][1]表示第i天不持有股票所能拥有的最大利润
2. 状态转移方程
- 每一个状态都有两种到达方案，dp[i][0]有不操作和买入股票两种选择，dp[i][1]有不操作和卖出股票两种选择
- dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
- dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
3. 状态初始化
- dp[0][0] 表示第一天就持有股票，利润为-prices[0]
- dp[1][0] 表示第一天不持有股票，利润为0
```C++ []
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2));
        // 初始化
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i=1; i<len; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i][0] + prices[i]);
        }

        return dp[len-1][1];

    }
};
```

4. 优化
- 由于每一个状态都只与其前一个状态相关，因此采用两个变量即可
```C++ []
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        // 初始化
        int dp_0 = -prices[0];
        int dp_1 = 0;
        for(int i=1; i<prices.size(); i++)
        {
            dp_0 = max(dp_0, dp_1 - prices[i]);
            dp_1 = max(dp_1, dp_0 + prices[i]);
        }

        return dp_1;

    }
};
```



