### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size < 2)
            return 0;
        int dp[size][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(0, prices[1]-prices[0]);
        dp[1][1] = max(dp[0][1], -prices[1]);
        for(int i = 2; i < prices.size(); ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);   
            dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]); // 一定要注意买入的时候，比的是上上次卖出的时候
        }
        return dp[size-1][0];
    }
};
```