```
#define TWO 2
int max(int a, int b)
{
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    // 明确状态 -- dp[i][0] dp[i][1]的值都表示 当天最大收益
    // 明确dp含义 -- dp[i][0] 不持有 dp[i][1] 持有
    // 明确状态转移方程 dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]); 
    //                  dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
    // 明确base case dp[0][0] = 0; dp[0][1] = -prices[0];
    int i;
    if (prices == NULL || pricesSize < 2) {
        return 0;
    }
    int **dp = (int**)malloc(sizeof(int*) * pricesSize);
    for (i = 0; i < pricesSize; i++) {
        dp[i] = (int*)malloc(sizeof(int) * TWO);
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    dp[0][0] = 0; 
    dp[0][1] = -prices[0];

    for (i = 1; i < pricesSize; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]); 
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
    }
    return dp[pricesSize - 1][0];
}
```
