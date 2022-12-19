### 解题思路
此处撰写解题思路

### 代码

```c
int min(int x,int y){
    return x>y? y:x;
}

int coinChange(int* coins, int coinsSize, int amount){
    int max = amount + 1,i,j;
    int dp[amount+1];
    dp[0] = 0;
    for(i = 1;i < amount+1;i++)
        dp[i] = max;
    for(i = 1;i <= amount;i++){
        for(j = 0;j < coinsSize;j++){
            if(i>=coins[j])
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
        }
    }
    return dp[amount]>amount? -1:dp[amount];
}
```