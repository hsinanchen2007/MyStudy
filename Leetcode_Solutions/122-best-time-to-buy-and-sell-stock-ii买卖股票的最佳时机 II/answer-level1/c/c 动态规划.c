### 解题思路
/*
dp[i][k][0] = MAX(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
dp[i][k][1] = MAX(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
base case 
dp[-1][k][0] = 0;
dp[-1][k][1] = -32768
dp[i][0][0] = 0;
dp[i][0][1] = -32768
k = 无穷大时， dp[i-1][k-1][0] = dp[i-1][k][0]
化简
dp[i][0] = MAX(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = MAX(dp[i-1][1], dp[i-1][0] - prices[i]);

dp[0][0] = 0;
dp[0][1] = -prices[0];
*/此处撰写解题思路

### 代码

```c
/*
dp[i][k][0] = MAX(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
dp[i][k][1] = MAX(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
base case 
dp[-1][k][0] = 0;
dp[-1][k][1] = -32768
dp[i][0][0] = 0;
dp[i][0][1] = -32768
k = 无穷大时， dp[i-1][k-1][0] = dp[i-1][k][0]
化简
dp[i][0] = MAX(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = MAX(dp[i-1][1], dp[i-1][0] - prices[i]);

dp[0][0] = 0;
dp[0][1] = -prices[0];
*/
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int dp[50000][2];
int maxProfit(int* prices, int pricesSize){
    int i;
    if (pricesSize == 0 || prices == NULL) {
        return 0;
    }
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (i = 1; i < pricesSize; i++) {
        dp[i][0] = MAX(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = MAX(dp[i-1][1], dp[i-1][0] - prices[i]);
    }
    return dp[pricesSize-1][0];
}


```