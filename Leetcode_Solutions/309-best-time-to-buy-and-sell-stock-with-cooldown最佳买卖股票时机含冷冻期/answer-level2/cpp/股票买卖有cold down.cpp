### 解题思路
此题的解题思路是利用动态规划的思想，首先需要定义dp状态和状态转移方程；
因为仍然可以交易无限次，所以交易次数这个维度可以不考虑，写出的dp方程如下：
dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-2][0]-price[i])
需要记录前天的dp，因为有cold down
### 代码

```cpp
/*
dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-2][0]-price[i])
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_pre_0 = 0;
        int dp_i_0 = 0;
        int dp_i_1 = -65535;
        for(int i=0; i<n; i++)
        {
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0,dp_i_1+prices[i]);
            dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
            dp_pre_0 = tmp;
        }
        return dp_i_0;
    }
};
```