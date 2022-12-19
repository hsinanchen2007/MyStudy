### 解题思路
此处撰写解题思路

dp表示第i天的最大利润
今天的最大利润等于昨天的最大利润加上今天的股票价值减去昨天的股票价值，如果小于0，则取0

### 代码

```c
#define MAX_HTL(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize <= 1) {
        return 0;
    }

    /* dp表示第i天的最大利润
     * 今天的最大利润等于昨天的最大利润加上今天的股票价值减去昨天的股票价值，如果小于0，则取0
     */
     int *dp = (int *)malloc(sizeof(int) * pricesSize);
     int max = 0;
     memset(dp, 0, sizeof(int) * pricesSize);
     
    for (int i = 1; i < pricesSize; i++) {
        dp[i]  = dp[i - 1] + prices[i] - prices[i - 1];
        dp[i] = MAX_HTL(dp[i], 0);
        max = MAX_HTL(max, dp[i]);
    }

    free(dp);
    return max;
}
```