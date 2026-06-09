### 解题思路
暴力求解，只要是第二天比今天的高就卖出一次，抓住每一次的涨。这就是没有费率的好处，哈哈。

### 代码

```c
int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize <= 1)
    {
        return 0;
    }
    int ret = 0;
    for(int i = 0; i < (pricesSize-1); i++)
    {
        if((prices[i+1]-prices[i])>0)
            ret += (prices[i+1]-prices[i]);
    }
    return ret;
}
```