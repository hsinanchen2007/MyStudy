### 解题思路


### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int low=0,high=0,max=0;
    for(int i=0;i<pricesSize;i++){
        for(int j=i+1;j<pricesSize;j++){
            if(prices[i]<prices[j]){
                if(prices[j]-prices[i]>max) {
                    max=prices[j]-prices[i];
                    low=i;
                    high=j;
                }
            }
        }
    }
    if(low<high) return prices[high]-prices[low];
    else return 0;
}
```