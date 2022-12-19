```
int maxProfit(int* prices, int pricesSize)
{   
    int profit = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        int x = prices[i] - prices[i-1];  //一发现明天价格要下跌，就卖出
        if (x > 0) profit += x;
    }
    return profit;
}
```
