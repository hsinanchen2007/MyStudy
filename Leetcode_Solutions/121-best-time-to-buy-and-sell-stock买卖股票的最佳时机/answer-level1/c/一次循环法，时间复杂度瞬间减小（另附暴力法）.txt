### 解题思路
此处撰写解题思路
先找到最小买入点，假设找到的点为最小买入点，那么就看价格差，是否比当前最大利润大。具体看代码
### 代码

```c
// int maxProfit(int* prices, int pricesSize){
//     int max=0;
//     for(int i=0;i<pricesSize-1;i++){
//         for(int j=i+1;j<pricesSize;j++){
//             int de=prices[j]-prices[i];
//             if(max<de)
//                 max=de;
//         }
        
//     }
//     return max;
// }
int maxProfit(int* prices, int pricesSize){
    int max=0,minprice=60000;
    for(int i=0;i<pricesSize;i++){
            if(minprice>prices[i])
                minprice=prices[i];
            else if(max<prices[i]-minprice){
                max=prices[i]-minprice;
            }
        
    }
    return max;
}
```