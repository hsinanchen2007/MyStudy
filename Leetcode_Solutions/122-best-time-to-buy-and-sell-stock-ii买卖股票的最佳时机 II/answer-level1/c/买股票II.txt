### 解题思路
关键在于最后一天 如果还持有，则要卖；

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    //I中用了历史最低点的方法
    //II中则分成了多个子数组
    //股票卖出的时机是下降之前且prof>0
    int canbuy=1,cansell=0;

    int holdprice=0;
    int sellprice=0;
    int prosum=0;
    for(int i=0;i<pricesSize-1;i++)
    {
        if(prices[i]<prices[i+1]&&canbuy==1)
        {
            cansell=1;
            canbuy=0;
            holdprice=prices[i];
        }
        if(prices[i]>prices[i+1]&&cansell==1)
        {
             cansell=0;
             canbuy=1;
             prosum+=prices[i]-holdprice;
        }
        
    }
    if(cansell)
        prosum+=prices[pricesSize-1]-holdprice;
    return prosum;

}
```