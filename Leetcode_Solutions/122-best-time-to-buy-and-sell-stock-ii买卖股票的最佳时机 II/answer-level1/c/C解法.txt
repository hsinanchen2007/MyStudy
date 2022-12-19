
这题核心可以从价格爬坡理解，价格上涨，我们收益就会增加，如果价格下降，我们就选择不卖出。

```
int maxProfitII(int* prices, int pricesSize){
    
    if (pricesSize == 0||pricesSize == 1) {
        return 0;
    }
    
    int profit = 0;
    int lastPrice = prices[0];
    
    for (int i = 1; i < pricesSize; i++) {
        
        if (prices[i] > lastPrice) {
            profit = profit + prices[i] - lastPrice;
        }
       
        lastPrice = prices[i];
    }
 
    return profit;
    
}
```
