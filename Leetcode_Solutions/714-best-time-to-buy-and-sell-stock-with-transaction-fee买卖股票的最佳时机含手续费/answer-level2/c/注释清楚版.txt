### 解题思路
看题干，买入是不需要手续费的。在卖出的时候结算一次手续费。

### 代码

```c
int max(int a, int b)
{
    return a > b ? (a) : (b);
}

int maxProfit(int* prices, int pricesSize, int fee) {
    int dp[pricesSize][2]; 
    dp[0][0] = 0; //dp[i][0] i天未持有, dp[i][1] i天持有
    dp[0][1] = 0 - prices[0];
    int i;

    for (i = 1; i< pricesSize; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee); // 今天未持有：1)保持前一天没持有 2）前一天持有,今天卖了
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // 今天持有： 1）前一天持有保持到今天 2）前一天每持有,买入
    }

    return max(dp[pricesSize - 1][0], dp[pricesSize - 1][1]);
}
```