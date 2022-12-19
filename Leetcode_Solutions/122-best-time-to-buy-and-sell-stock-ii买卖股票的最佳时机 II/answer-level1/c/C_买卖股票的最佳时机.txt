### 解题思路
股票每天都交易，如果明天的价格比今天的高，今天就买入；如果明天的价格比今天的低，今天就卖出。

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int result=0;
    for(int i=0;i<pricesSize-1;++i)
        result=prices[i+1]-prices[i]>0?result+prices[i+1]-prices[i]:result;
    return result;
}
```