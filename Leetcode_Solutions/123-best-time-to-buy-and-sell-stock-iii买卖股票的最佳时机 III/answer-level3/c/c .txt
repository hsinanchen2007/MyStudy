### 解题思路
此处撰写解题思路

### 代码

```c
/*
    dp[i][k][0] = MAX(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
    dp[i][k][1] = MAX(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);

    base case
    dp[-1][k][0] = 0;
    dp[-1][k][1] = -32768;
    dp[i][0][0] = 0;
    dp[i][0][1] = -32768;

    dp[0][0][0] = 0;
    dp[0][0][1] = -32768;
    dp[0][1][0] = 0;
    dp[0][1][1] = -prices[0];
*/

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int dp[100000][3][2];
int maxProfit(int* prices, int pricesSize){
    int i ,k;
    if(prices == NULL || pricesSize == 0) {
        return 0;
    }
    memset(dp, 0, sizeof(dp));
 //   for (i = 0; i < pricesSize; i++) {
    dp[0][1][0] = 0;
    dp[0][1][1] = -prices[0];
    dp[0][0][0] = 0;
    dp[0][0][1] = -32768;
    dp[0][1][1] = -prices[0];
    dp[0][2][1] = -prices[0];

 //   }
    for (i = 1; i < pricesSize; i++) {
        for (k = 1; k <=2; k++) {
           dp[i][k][0] = MAX(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
           dp[i][k][1] = MAX(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);            
        }
    }
    return dp[pricesSize-1][2][0];
}
```