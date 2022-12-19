//思路：动态规划状态：dp[amount]，前idx个硬币可以组成amount金额的组合数，dp[m]+dp[m-coin[idx]] ， dp[m]为用第idx硬币的组合数， dp[m-coin[idx]]为不用第idx的组合数
//amount =0时，只有一种dp[0]=1
//只有amount大于当前coin时才有组合
```
int change(int amount, int* coins, int coinsSize){
    int dp[5000+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int idx = 0; idx < coinsSize; idx++) {
        for (int m = coins[idx]; m < amount + 1; ++m) {
            dp[m] += dp[m - coins[idx]];
            printf("m=%d dp=%d\n", m, dp[m]);
        }
    }
    return dp[amount];
}
```
