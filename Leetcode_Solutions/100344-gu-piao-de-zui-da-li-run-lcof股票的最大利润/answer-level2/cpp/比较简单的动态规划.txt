### 解题思路
一、暴力法容易理解，求出最大的prices[j]-prices[i],j>=i。结果是肯定超时了。
二、动态规划。
这一题的动态规划只用了一维数组来保存当天之前的最低股票价格。
dp[0]:第一天之前的最低股票价格
dp[1]:第二天之前的最低股票价格
dp[2]:第三天之前的最低股票价格
.
.
.
然后用当天的股票价格prices[i]-dp[i]，就能得到当天股票交易能获取的最大利润（最高价卖出-最低价买入）
利用maxprofit保存每一天股票交易的最大利润，并且不停地更新maxprofit即可。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;

        //dp[i]的意思：i时间之前的最低股票价格
        //i=0：第一天之前的股票最低价格
        //i=1：第二天之前的股票最低价格
        vector<int> dp(len);
        dp[0] = prices[0];

        int maxprofit = 0;
        for (int i = 1; i < len; i++) {
            dp[i] = min(dp[i - 1], prices[i]);
            maxprofit = max(maxprofit, prices[i] - dp[i]);
        }

        return maxprofit;
    }
};
```