### 解题思路
动态规划，三维数组的状态可以降维二维，因为每一次交易应该只和上一天有关系

### 代码

```c
#define MAX(a,b) (a>b?a:b)
int maxProfit2(int* prices, int pricesSize) {
	int dp0 = 0; //售出
	int dp1 = -prices[0]; //买入
	for (int i = 1; i < pricesSize; i++) {
		int temp = dp0;
		dp0 = MAX(dp0, dp1 + prices[i]);
		dp1 = MAX(dp1, temp - prices[i]);
	}
	return dp0;
}
int maxProfit(int k, int* prices, int pricesSize) {
	if (pricesSize <= 1) return 0;
	if (k >= pricesSize / 2)
		return maxProfit2(prices, pricesSize);
	int dp[pricesSize][k+1][2] ;
    memset(dp,0,sizeof(int)*pricesSize*(k+1)*2);
	for (int i = 0; i < pricesSize; i++)
		for (int j = k; j >= 1; j--) {
			if (i == 0) {
				dp[i][j][0] = 0;
				dp[i][j][1] = -prices[0];
				continue;
			}
			dp[i][j][0] = MAX(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
			dp[i][j][1] = MAX(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
		}
	return dp[pricesSize - 1][k][0];
}


```