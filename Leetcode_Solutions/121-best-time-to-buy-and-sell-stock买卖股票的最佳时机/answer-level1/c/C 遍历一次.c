### 解题思路
历史最低点，遍历一次；
每一天卖的时候，需要知道当前时刻对应的历史最低点。
每过一天，更新一次历史最低点（可能是今天，也可能是原来的历史最低点）
并比较利润与以前的最大利润；
返回最大利润

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    if(pricesSize<2)
        return 0;
    //if sold on day i, should bought on day[0,i-1]
    int Lowest=prices[0];
    int prof=0;
    for(int i=1;i<pricesSize;i++)
    {
        prof=((prices[i]-Lowest)>prof)?(prices[i]-Lowest):prof;
        if(prices[i]<Lowest)
        Lowest=prices[i];

    }
    return prof;
}
```