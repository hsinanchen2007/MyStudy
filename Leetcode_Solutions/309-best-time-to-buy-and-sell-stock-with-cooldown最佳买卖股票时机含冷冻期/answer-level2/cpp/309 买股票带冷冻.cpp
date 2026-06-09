### 解题思路
转移方程
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
参考
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-lab/
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;       
        int days = prices.size();
        vector<vector<int>> dp;
        for (int i = 0; i < days; i++) {
            vector<int> v(2, 0);
            dp.push_back(v);
        }
        int res = 0;
        for (int i = 0; i < days; i++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = 0 - prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            if (i <= 1) {
                dp[i][1] = max(dp[i-1][1],  - prices[i]);
            } else {
                dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
            }
            
            res = max(res, dp[i][0]);
        }
        
        return res;
    }
};
```