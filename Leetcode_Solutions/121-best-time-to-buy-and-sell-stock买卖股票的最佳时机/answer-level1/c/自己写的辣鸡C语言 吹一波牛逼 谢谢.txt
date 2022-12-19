### 解题思路
思路就是加呗

### 代码

```c
int maxProfit(int* prices, int pricesSize){
     int i,j,max=-12132,money;
     for(i=0;i<pricesSize;i++){
         for(j=i+1;j<pricesSize;j++){
             money=prices[j]-prices[i];
             if(money>max){
                 max=money;
             }
         }
     }
     if(max<0){
         max=0;
     }
     return max;
}
```