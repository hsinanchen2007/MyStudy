### 解题思路
双重数组dp实现股票买卖算法
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)
            return 0;
        int dp[n][2];
        for (int i = 0; i < n; i++) {
            if (i - 1 == -1) { 
                dp[i][0] = 0; 
                dp[i][1] =  -prices[i];
                continue;           
            } 
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);              
            dp[i][1] = max(dp[i-1][1], -prices[i]); 
        }
            return dp[n - 1][0];
    }
};
```