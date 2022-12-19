分析:
先计算当前位置一次进行一次交易的最大利润,保存每个位置的最大利润
第二次计算，逆序计算，以当前位置作为第二次买入的起点 计算此时第二次购入的最大利润，与前方第一次买入的利润相加，更新总利润
```
int maxProfit(int* prices, int pricesSize){
    if(pricesSize<2)return 0;
    int *profit=(int *)calloc(pricesSize,sizeof(int ));
    //第一次交易
    int sum=0;
    int max=0;
    for(int i=1;i<pricesSize;i++)
    {
        sum+=prices[i]-prices[i-1];
        if(prices[i]-prices[i-1]>0)max=sum>max?sum:max;
        if(sum<0)sum=0;
        profit[i]=max;
    }
    sum=0;
    max=profit[pricesSize-1];
    for(int i=pricesSize-2;i>1;i--)
    {//第二次交易
        sum+=prices[i+1]-prices[i];
        if(prices[i+1]-prices[i]>0)max=sum+profit[i-1]>max?sum+profit[i-1]:max;
        if(sum<0)sum=0;
    }
    free(profit);
    return max;
}
```