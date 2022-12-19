```
int maxProfit(int* prices, int pricesSize){
    if(pricesSize < 2) {
        return 0;
    }
    int dp[pricesSize][2][3];
    int i;
    int max = 0;

    dp[0][0][2] = 0;
    dp[0][1][1] = -prices[0];
    dp[0][0][1] = -10000;
    dp[0][1][0] = -10000;
    dp[0][0][0] = -10000;

    for(i = 1; i < pricesSize; i++) {
        dp[i][0][2] = dp[i - 1][0][2];
        dp[i][1][1] = fmax(dp[i - 1][1][1], dp[i - 1][0][2] - prices[i]);
        dp[i][0][1] = fmax(dp[i - 1][0][1], dp[i - 1][1][1] + prices[i]);
        dp[i][1][0] = fmax(dp[i - 1][1][0], dp[i - 1][0][1] - prices[i]);
        dp[i][0][0] = fmax(dp[i - 1][0][0], dp[i - 1][1][0] + prices[i]);
        printf("%d  ", dp[i][0][1]);
    }

    for(i = 0; i < pricesSize; i++) {
        max = fmax(max, dp[i][0][1]);
        max = fmax(max, dp[i][0][0]);
    }
    return max;
}
```
