### 解题思路
此处撰写解题思路

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int max_difference=0, difference;
    for(int i=0;i<pricesSize;i++)
    {
        difference=0;
        for(int j=i+1;j<pricesSize;j++)
        {
            if(prices[j]-prices[i]>difference)
            difference=prices[j]-prices[i];
        }
        if(max_difference<difference)
        max_difference=difference;
    }
    if(!max_difference)
    return 0;
    else
    return max_difference;

}
```