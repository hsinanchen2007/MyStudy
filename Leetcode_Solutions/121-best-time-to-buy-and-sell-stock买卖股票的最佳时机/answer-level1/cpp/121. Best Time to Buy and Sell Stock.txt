### 解题思路
又是一维动态规划体型，感觉不太好确立状态表达式：
dp[i]: 前面i天能够获取的最大利润
dp[i] = max(dp[i-1],prices[i] - min) 

### 代码

```cpp
class Solution {
public:
    //dp[i]: 在第i天卖出能获取到的最大利润???
    //dp[i] = dp[i-1] + prices[i] - prices[i-1]

    //dp[i][j]: 在i天买入，j天卖出获取到的利润？
    //dp[i][j] = ?????????????

    //dp[i]: 前面i天能够获取的最大利润
    //dp[i] = max(dp[i-1],prices[i] - min) 
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int minPrice = prices[0];
        int dp[prices.size()] = {0};
        dp[0] = 0;
        for(int i = 1; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            dp[i] = max(dp[i-1],prices[i] - minPrice);
        }
        return dp[prices.size()-1];
    }
};
```
参考：
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/gu-piao-wen-ti-python3-c-by-z1m/