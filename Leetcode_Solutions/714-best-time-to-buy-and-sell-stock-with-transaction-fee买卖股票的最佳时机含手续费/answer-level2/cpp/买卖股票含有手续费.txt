### 解题思路
利用动态规划的思想，dp方程定义如下：
股票买卖含有手续费，可以交易无数次，但是有手续费
dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-1][0]-price[i]-fee)

### 代码

```cpp
/*
dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-1][0]-price[i]-fee)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp_i_0 = 0;
        int dp_i_1 = -65535;
        for(int i=0; i<n; i++)
        {
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1+prices[i]);
            dp_i_1 = max(dp_i_1, tmp - prices[i] -fee);
        }
        return dp_i_0;
    }
};
```