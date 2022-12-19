### 解题思路
股价一直下降到最低点(谷)时买，记录下这个buyprice。股价上升就赚钱，一直上升一直赚钱，到达与最低点相邻的最高点(峰)时就卖掉。

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    if(pricesSize<2){
        return 0;
    }
    int buyprice=prices[0],result=0;
    for(int i=1;i<pricesSize;i++){
        if(prices[i]<=buyprice){
            buyprice = prices[i];
        }else{
            result += prices[i]-buyprice;
            buyprice = prices[i];
        }
    }
    return result;
}
```