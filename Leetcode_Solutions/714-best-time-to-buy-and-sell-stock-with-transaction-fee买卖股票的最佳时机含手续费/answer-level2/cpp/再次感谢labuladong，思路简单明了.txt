```
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size=prices.size();
        if(size==0) return 0;
        int dp[size][2]={0};
        for(int i=0;i<size;i++)
        {
            if(i==0)
            {
                dp[i][0]=0;
                dp[i][1]=-prices[i];
            }
            else
            {
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
                dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
            }
        }
        return dp[size-1][0];
    }
};
```
