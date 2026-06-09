### 解题思路
这题炒股人每一天有4种状态，分别是
1. 不持有股票   dp[i][0]
2. 当天买入     dp[i][1]
3. 持有股票     dp[i][2]
4. 当天卖出     dp[i][3]
则转移方程是
1. `dp[i][0] = max(dp[i-1][0], dp[i-1][3]); //第i天不持有的最多钱，是max(第i-1天不持有, 第i-1天卖出)`
2. `dp[i][1] = dp[i-1][0] - prices[i];      //有空挡期，则买入必须用第i-1天的不持有股票所剩余的钱够买`
3. `dp[i][2] = max(dp[i-1][1], dp[i-1][2]); //持有股票最高获利，是max(第i-1天购入，第i-1天持有)，
第i-1天持有相当于第i天以前卖出所有股票后，购入股票的最低价`
4. `dp[i][3] = max(dp[i-1][1], dp[i-1][2]) + prices[i]; //卖出，第i-1天买入与持有比，获利大的那个加上i天的价格`



### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        //dp是个 [prices.size()] * [4] 的2维数组，
        //对于dp[i][j]，是以第i天为末尾的 不持有股票、买入、持有、卖出操作
        //  的当前剩余钱
        vector<int> dp1(4, 0);//idle, buy, hold, sell
        vector<vector<int>> dp(size, dp1);

        if (size < 2)   //别买了
        {
            return 0;
        }
        //初始化第一天的情况
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = -prices[0];//这里第一天的持有股票设置成购入，
        dp[0][3] = 0;
        int maxsum = INT_MIN;

        for (int i = 1; i < prices.size(); i++)
        {
            //第i天不持有的最多钱，是max(第i-1天不持有, 第i-1天卖出)
            dp[i][0] = max(dp[i-1][0], dp[i-1][3]);
            //有空挡期，则买入必须用第i-1天的不持有股票所剩余的钱够买
            dp[i][1] = dp[i-1][0] - prices[i];
            //持有股票最高获利，是max(第i-1天购入，第i-1天持有)，
            //第i-1天持有相当于第i天以前卖出所有股票后，购入股票的最低价
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
            //卖出，第i-1天买入与持有比，获利大的那个加上i天的价格
            dp[i][3] = max(dp[i-1][1], dp[i-1][2]) + prices[i];
            if (maxsum < dp[i][3])//更新卖出的最高价
            {
                maxsum = dp[i][3];
            }
        }
        return max(maxsum, 0);//0就是别买了，不赚的
    }
};
```