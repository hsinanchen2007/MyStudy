### 解题思路
此处撰写解题思路
可以先算出第几天卖出的利润，第一天的利润为0，第二天的利润为prices[i] - prices[i-1]，这样可以算出相邻两天卖出的利润，
然后如果再算最大利润，若前一天的利润大于0，则今天的利润，为前一天卖出加上今天卖出的利润，否则今天卖出的最大利润就为0                                                                                                                                                                                                                                                                                                                                                                          
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1)
        return 0;
        int dp[len];
        dp[0] = 0;
        for(int i = 1; i < len; i++){
            dp[i] = prices[i] - prices[i - 1];
        }
        int ans[len];
        ans[0] = 0;
        int profit = 0;
        for(int i = 1; i < len; i++){
            ans[i] = max(0,ans[i - 1] + dp[i]);
            profit = max(profit,ans[i]);
        }
        return profit;
    }
};
```