### 解题思路
此处撰写解题思路

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    /*int i,j;
    int sum = 0;
    
    if(prices == NULL || pricesSize <= 0)
        return 0;
    int temp= prices[0];

    for(i=0;i<pricesSize;i++)
    {
        if(prices[i]>temp)
            continue;
        else
            temp = prices[i];
        for(j=i+1;j<pricesSize;j++)
        {
            if(prices[j]<=prices[i])
                continue;
            sum = ((prices[j]-prices[i]) > sum)?prices[j]-prices[i]:sum;
        }
    }
    return sum;*/


    int i,min,max,sum=0;
    if(prices == NULL || pricesSize <= 0)
        return 0;
    min = prices[0];
    max = min;
    for(i=1;i<pricesSize;i++)
    {
        if(prices[i]<min)
        {
            min=prices[i];
            max=prices[i];
        }
        if(prices[i]>min)
        {
            if(prices[i]>max)
            {
                max = prices[i];
                sum = (max-min)>sum?max-min:sum;
            }
        }
    }
    return sum;
}
```