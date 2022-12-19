### 解题思路
动态规划

### 代码

```c
#define MAX(a,b) (a>b?a:b)
int maxProfit(int* prices, int pricesSize){
    if(pricesSize<=1) return 0;
    int dp0 = 0;
	int dp0_pre = 0;
	int dp1 = -prices[0];
	for (int i = 1; i < pricesSize; i++) {
		int temp = dp0;
		dp0 = MAX(dp0, dp1 + prices[i]);
		dp1 = MAX(dp0_pre - prices[i], dp1);
		dp0_pre = temp;
	}
	return dp0;

}
```