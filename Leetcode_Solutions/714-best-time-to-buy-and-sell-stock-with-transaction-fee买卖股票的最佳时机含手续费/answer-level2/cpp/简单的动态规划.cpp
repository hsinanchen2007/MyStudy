
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s=prices.size();
        int dp[50000][2];//dp[i][k] 第i天，j = 0 表示不持股，j = 1 表示持股
        dp[0][0]=0;
        dp[0][1]=-prices[0]-fee;
        for(int i=1;i<s;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]-fee);
        }
        return dp[s-1][0];
    }
};
```