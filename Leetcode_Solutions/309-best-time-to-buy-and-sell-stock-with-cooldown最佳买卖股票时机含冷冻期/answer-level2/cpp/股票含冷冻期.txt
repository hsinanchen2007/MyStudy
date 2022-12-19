### 解题思路
二维数组dp[i][j]代表第i天时手里没有股票(j=0)和手里有股票(j=1)时的收益

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if(days <2)
            return 0;
        
        vector<vector<int>>dp(days,vector<int>(2));
        int res = INT_MIN;
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(0,prices[1]-prices[0]);
        dp[1][1] = max(dp[0][1],-prices[1]);
        if(days == 2)
            return dp[1][0]>dp[1][1]?dp[1][0]:dp[1][1];
        for(int i = 2;i < days;i++){
            //没股票时有两种可能：上一天时就没有，上一天时有今天卖了
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            //有股票时有两种可能：上一天时就有，上一天时没有今天买入
            dp[i][1] = max(dp[i-1][1],dp[i-2][0]-prices[i]);
           
            int day_max = max(dp[i][0],dp[i][1]);
            res = day_max > res?day_max:res;
        }
        
        return dp[days-1][0];
    }
};
```