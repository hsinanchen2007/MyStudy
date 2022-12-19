### 解题思路
定义变量buy和sell表示买入和卖出的下标，因为卖出一定在买入后面，因此定义利润变量profit，每当sell-buy大于profit时就存入新的利润，因为求最大利润所以要保证买入的值尽可能小，因此当sell小于buy的值是将buy变为sell的值。

### 代码

```c


int maxProfit(int* prices, int pricesSize){
    if (pricesSize==0)
        return 0;
    int buy=0,sell=0;
    int profit=0;
    for(sell=0;sell<pricesSize;sell++)
    {
        if(prices[buy]>prices[sell])
            buy=sell;
        if(profit<prices[sell]-prices[buy])
            profit=prices[sell]-prices[buy];
    }
    return profit;
}


```