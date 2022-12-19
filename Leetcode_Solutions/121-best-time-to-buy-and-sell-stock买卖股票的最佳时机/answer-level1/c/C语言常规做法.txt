```c
int maxProfit(int* prices, int pricesSize){
    int i,j,max=0;
    for (i=0;i<pricesSize;i++)
        for(j=i+1;j<pricesSize;j++)
            if(prices[j]-prices[i]>max) max=prices[j]-prices[i];
    return max;
}
```