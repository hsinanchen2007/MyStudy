dp[i]表示能组成i的硬币的最少个数。

转移方程为:
**dp[i]=min(dp[i],dp[i-coins[j]]+1);其中j<coins.size() and coins[j]<=i;**

这里排序和不排序都行，排序了遍历到不满足条件就结束，不排序就需要遍历coins数组里面的每个是否小于i
```
int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==0 && amount==0)
            return 0;
        if(coins.size()==0 && amount!=0)
            return -1;
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,0x3f3f3f3f);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size() && coins[j]<=i;j++)
            {
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        if(dp[amount]==0x3f3f3f3f)
            return -1;
        return dp[amount];
    }
```
