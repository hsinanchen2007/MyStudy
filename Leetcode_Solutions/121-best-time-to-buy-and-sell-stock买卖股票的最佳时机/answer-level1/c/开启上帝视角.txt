### 解题思路
动态规划，开启上帝视角后面利润会不会超过现在。

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    if(pricesSize==0)
        return 0;
    int profit=0,i,j,mprofit=0;;
    for(i=0,j=0;j<pricesSize;j++)
    {
        if(prices[i]>prices[j])
           i=j;
        else if(prices[i]<prices[j])
        {profit=prices[j]-prices[i];
        if(profit>mprofit)
             mprofit=profit;
        }
    }
    return mprofit;   
}
```