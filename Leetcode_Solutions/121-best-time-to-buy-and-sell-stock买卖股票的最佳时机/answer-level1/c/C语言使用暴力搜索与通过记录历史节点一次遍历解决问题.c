方法一：暴力搜索
``` 
int maxProfit(int* prices, int pricesSize){
    int max_profit = 0;

    for (int i = 1; i < pricesSize; ++i) {
        for (int j = i + 1; j < pricesSize; ++j) {
            max_profit = max_profit > prices[j] - prices[i] ? max_profit : prices[j] - prices[i];
        }
    }
    return max_profit;
}
```
方法二：一次遍历
```
int maxProfit(int* prices, int pricesSize){
    int max_profit = 0;
    if (pricesSize == 0) {
        return max_profit;
    }
    int min_price = prices[0]; // 记录历史最低价格
    for (int i = 1; i < pricesSize; ++i) {
        max_profit = max_profit > prices[i] - min_price ? max_profit : prices[i] - min_price;
        if (min_price > prices[i]) { 
            min_price = prices[i];
        }
    }
    return max_profit;
}
```


