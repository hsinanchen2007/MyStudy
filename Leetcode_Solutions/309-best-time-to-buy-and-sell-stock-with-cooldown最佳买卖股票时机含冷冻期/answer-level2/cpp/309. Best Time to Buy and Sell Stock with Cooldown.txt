### 解题思路
DP

![6e6fd51487bd5285241a64dd8cc07ef.jpg](https://pic.leetcode-cn.com/220765f0a51f304fff12ad03e6bd9d08f2b02cd8854e593391d8f4f9eb499f1c-6e6fd51487bd5285241a64dd8cc07ef.jpg)


### 代码

```cpp
class Solution {
public:
    //dp[i]: 在第i天执行买入卖出或者暂停交易所获取的最大利润
    //buy[i] = max(buy[i-1], cool[i-1] - prices[i])
    //sell[i] = buy[i-1] + prices[i]
    //cool[i] = max(cool[i-1], sell[i-1])
    int maxProfit(vector<int>& prices) {
        //int maxProfit = 0;

        //int buy[prices.size()] = {0};
        //int sell[prices.size()] = {0};
        //int cool[prices.size()] = {0};
        if(prices.empty())
            return 0; 
        //初始化第一天
        int buy = -prices[0];//第一天买入利润为支出
        int sell = INT_MIN;//第一天不可能卖出，初始化为最小值
        int cool = 0;//第一天也可以不用交易，利润为0
        for(int i = 1; i < prices.size(); i++){
            int prev_sell = sell;
            sell = buy + prices[i];
            buy = max(buy, cool - prices[i]);
            cool = max(cool, prev_sell);
        }
        return max(max(buy, sell), cool);
    }
};
```