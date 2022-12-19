### 解题思路
dp[i][j]表示i买入但j可卖出或不卖出的最大价值。
利用01背包的简化公式
dp[j]表示在j处时的最大价格，包括卖出j或者没卖的结果
以下是在j处卖出的最大价值
if (i <= 2) dp[j] = max(dp[j], prices[j] - prices[i]);
else dp[j] = max(dp[j], dp[i-2] + prices[j] - prices[i]);
最后需要再加上与前一个的比较（没卖），可能此时没卖比卖了的要高
dp[j] = max(dp[j], dp[j-1]);

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> dp(len);
        if (len == 0) return 0;
        for (int i=0; i<len-1; i++) {
            for (int j=len-1; j>i; j--) {
                if (i <= 2) dp[j] = max(dp[j], prices[j] - prices[i]);
                else dp[j] = max(dp[j], dp[i-2] + prices[j] - prices[i]);
                dp[j] = max(dp[j], dp[j-1]);
            }
        }
        return dp[len-1];
    }
};
```