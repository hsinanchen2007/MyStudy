### 解题思路
此处撰写解题思路

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int min = 9999;
    int max=0;
    int value;
    for(int i=0;i<pricesSize;i++){
        if(prices[i]<=min){
            min = prices[i];
        }
        else{
            value = prices[i]-min;
            if(max<value){
                max = value;
            }
        }
    }
    return max;
}
```
int maxProfit(int* prices, int pricesSize){
    int val;
    int max = 0;
    for(int i=0;i<pricesSize-1;i++){
        for(int j=i+1;j<pricesSize;j++){
            val=prices[j]-prices[i];
            if(val>max)max=val;
        }
    }
    return max;
}