### 解题思路
仔细审题会发现,这道题的要求是 You **may complete as many transactions as** you like
只要你的买入价格低于你第二天的卖出价格,你就可以买入,在价格出现下跌之前卖出,你就可以获利.
haveBuyFlag用来标记你手中是否有一份股票,当你手中持有股票的时候,你就不可以进行买入操作.
如果最后一天你的股票仍旧没有卖出,那么就把它卖出就行.

### 代码

```c
int maxProfit(int* prices, int pricesSize)
{
    int i, j;
    int buyPrice, sellPrice;
    int sum  = 0;
    int haveBuyFlag = 0;
    if(pricesSize <= 1) return 0;
    for(i = 0; i < pricesSize-1; i++)
    {
        if(prices[i+1] > prices[i] && haveBuyFlag == 0)
        {
            haveBuyFlag = 1;
            buyPrice = prices[i];
        }
        else if(prices[i+1] <= prices[i])
        {
            if(haveBuyFlag)
            {
                sellPrice = prices[i];
                sum += (sellPrice - buyPrice);
                haveBuyFlag = 0;
            }
        }
    }
    if(i == pricesSize-1 && haveBuyFlag)
    {
        sum += (prices[i]-buyPrice);
    }
    return sum;
}
```