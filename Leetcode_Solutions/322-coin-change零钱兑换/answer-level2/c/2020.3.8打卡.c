### 解题思路
此处撰写解题思路
dp
### 代码

```c
int coinChange(int* coins, int coinsSize, int amount){
    int dp[amount+1];
    const int IMAX=INT_MAX;
   // memset(dp,IMAX,amount+1);
    
   // printf("IMax=%d dp[1]=%d\n",IMAX,dp[1]);

    dp[0]=0;
    for(int i=1;i<=amount;i++)
    {
        dp[i]=INT_MAX;
        for(int j=0;j<coinsSize;j++)
        {
            if(i>=coins[j] && dp[i-coins[j]]!=IMAX)
            {
                dp[i]=dp[i]<(dp[i-coins[j]]+1)?dp[i]:(dp[i-coins[j]]+1);
            }
            //printf("j=%d dp[%d]=%d ",j,i,dp[i]);
        }
    }
    
    if(dp[amount]==IMAX && amount!=IMAX)
    {
        dp[amount]=-1;
    }

    return dp[amount];
}   
```