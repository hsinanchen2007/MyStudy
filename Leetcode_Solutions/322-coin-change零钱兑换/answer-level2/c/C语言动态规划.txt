#define MIN(A, B) ((A) < (B) ? (A) : (B))

int coinChange(int* coins, int coinsSize, int amount){
    int *dp;
    int ret;

    dp = (int *)malloc(sizeof(int) * (amount + 1));
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        dp[i] = amount + 1;
        for (int j = 0; j < coinsSize; j++) {
            if (i >= coins[j]) {
                dp[i] = MIN(dp[i], dp[i-coins[j]] + 1);  
            } 
        }
    }
    ret = dp[amount] > amount ? -1 : dp[amount];
    free(dp);

    return ret;
}