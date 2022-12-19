### 解题思路
动态规划

### 代码

```c
#define MAX(a,b) (a>b?a:b)
int maxProfit(int* prices, int pricesSize) {
    if(pricesSize<=1) return 0;
	int dp_i10 = 0, dp_i11 = -prices[0];
	int dp_i20 = 0, dp_i21 = -prices[0];
	for (int i = 1; i < pricesSize;i++) {
			dp_i20 = MAX(dp_i20, dp_i21 + prices[i]);
			dp_i21 = MAX(dp_i21, dp_i10 - prices[i]);
			dp_i10 = MAX(dp_i10, dp_i11 + prices[i]);
			dp_i11 = MAX(dp_i11, -prices[i]);
		}
		return dp_i20;
}
```