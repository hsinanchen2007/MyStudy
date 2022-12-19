```c
int maxProfit(int* prices, int pricesSize){
    short i;
    int profit=0;
    for(i=0;i<pricesSize-1;i++)
        if(prices[i]<prices[i+1])
            profit=profit+prices[i+1]-prices[i];
    return profit;
}
```