    int coinChange(int* coins, int coinsSize, int amount){
        if (amount == 0) {
            return 0;
        }
        int dp[amount + 1];
        int i;
        int j;
        for (i = 0; i <= amount; i++) {
            dp[i] = INT_MAX - amount;
        }
        for (i = 0; i <= amount; i++) {
            if (i == 0) {
                dp[i] = 0;
            }
            for (j = 0; j < coinsSize; j++) {
                if (coins[j] == 0) {
                    continue;
                }
                if (i - coins[j] >= 0) {
                    dp[i] = dp[i] > dp[i - coins[j]] + 1 ? dp[i - coins[j]] + 1 : dp[i];
                }
            }
        }
        if (dp[amount] >= INT_MAX - amount) {
            return -1;
        }
    
        return dp[amount];
    }