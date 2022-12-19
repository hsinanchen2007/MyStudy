### 解题思路
O(n)     每天的价格都与之前最小的买价做差，与之前的利润比较，并更新最小买价

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    if(pricesSize<2){
        return 0;
    }
    int buy=prices[0],result=0;
    for(int i=1;i<pricesSize;i++){
        if(result<prices[i]-buy){
            result = prices[i]-buy;
        }
        if(buy>prices[i]){
            buy = prices[i];
        }
    }
    return result;
}
```