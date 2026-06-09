### 解题思路
2层循环，为了防止先卖后买的情况，内层循环的开始值>外层循环值。


### 代码

```c
int maxProfit(int* prices, int pricesSize){

    int minBuy = 0;
    int maxPro = 0;

    if(prices == NULL
        || pricesSize == 0)
    {
        return 0;
    }

    for(int j=0; j<pricesSize; j++)
    {
        minBuy = prices[j];
        for(int i = j; i <pricesSize; i++)
        {
            if(maxPro < (prices[i] - minBuy))
                maxPro = prices[i] - minBuy;
            
        }

    }

    return maxPro;
}

```