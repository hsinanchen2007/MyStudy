采用最简单的方式，遍历整个数组并且比较，求取最大差价。
被各路大神解法吊打！！！


```
int maxProfit(int* prices, int pricesSize){
    int maxprofit = 0;
    int profit = 0;
    int i,j;
        for (i = 0; i < pricesSize - 1; i++) {
            for (j = i + 1; j < pricesSize; j++) {
                    profit = prices[j] - prices[i];
                    if (profit > maxprofit)
                        maxprofit = profit;
            }
        }
    return maxprofit;
}
```
