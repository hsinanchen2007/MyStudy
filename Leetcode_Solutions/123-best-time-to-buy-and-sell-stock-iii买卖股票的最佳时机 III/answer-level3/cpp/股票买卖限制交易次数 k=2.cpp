### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
dp[i][2][0] = max(dp[i-1][2][0],dp[i-1][2][1]+prices[i])
dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0]-price[i])
dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1]+price[i])
dp[i][1][1] = max(dp[i-1][1][1], -price[i])
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i_1_0 = 0;
        int dp_i_1_1 = -65535;
        int dp_i_2_0 = 0;
        int dp_i_2_1 = -65535;
        for(int i =0; i<n; i++)
        {
            dp_i_2_0 = max(dp_i_2_0, dp_i_2_1 + prices[i]);
            dp_i_2_1 = max(dp_i_2_1, dp_i_1_0 - prices[i]);
            dp_i_1_0 = max(dp_i_1_0, dp_i_1_1 + prices[i]);
            dp_i_1_1 = max(dp_i_1_1, -prices[i]);

        }
        return dp_i_2_0;
    }
};
```