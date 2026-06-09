### 解题思路
dp[i]记为i后面最大的数与prices[i]的差值，那么prices[i]+dp[i]即为i后面最大的数，
那么对于dp[i]，我们通过dp[i+1]+prices[i+1]可以得到i后面最大的值，
若prices[i] > dp[i+1]+prices[i+1]，说明i后面没有数字比它大，记为0，
否则，dp[i]记为两者差值，即dp[i+1]+prices[i+1]-prices[i]

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(),0);
        int res = 0;
        for(int i = dp.size()-2;i>=0;--i){
            int temp = prices[i+1] + dp[i+1];
            if(temp > prices[i])
                dp[i] = temp - prices[i];
            else
                dp[i] = 0;
            res = max(res,dp[i]);
        }
        return res;
    }
};
```