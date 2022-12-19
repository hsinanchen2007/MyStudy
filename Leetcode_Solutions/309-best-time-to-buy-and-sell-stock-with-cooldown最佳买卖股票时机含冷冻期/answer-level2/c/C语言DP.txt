# DP方程推导
**我们用DP[i][0]表示第i天不持有股票，用DP[i][1]表示第i天持有股票**

如果第i天不持有股票
可能是因为(i-1)天不持有股票
```
DP[i][0] = DP[i-1][0]
```
或者第(i-1)天持有股票，但是在第i天卖掉了
```
DP[i][0] = DP[i-1][1]+prices[i]
```
因为该题是求最大值，所以对于上述两种情况，我们取最大值，即
```
DP[i][0] = max(DP[i-1][0],DP[i-1][1]+prices[i])
```

同样的，如果第i天持有股票
可能是因为(i-1)天持有股票
```
DP[i][1] = DP[i-1][1]
```
或者第(i-2)天卖掉，在第i天又买入了
```
DP[i][1] = DP[i-2][0]-prices[i]
```
对于上述两种情况，我们取最大值，即
```
DP[i][1] = max(DP[i-1][1],DP[i-2][0]-prices[i])
```

# 代码
```
int maxProfit(int* prices, int pricesSize){
    int dpi0 = 0;
    int dpi1 = INT_MIN;
    int dpi2 = 0;
    int i;
    int temp;

    for (i = 0; i < pricesSize; i++) {
        temp = dpi0;
        dpi0 = fmax(dpi0, dpi1 + prices[i]);
        dpi1 = fmax(dpi1, dpi2 - prices[i]);
        dpi2 = temp;
    }

    return dpi0;
}
```
