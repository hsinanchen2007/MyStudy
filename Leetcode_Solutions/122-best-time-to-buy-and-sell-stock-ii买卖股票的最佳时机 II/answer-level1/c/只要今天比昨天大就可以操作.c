### 解题思路
此处撰写解题思路

### 代码

```c
int maxProfit(int* prices, int pricesSize){
int sum=0,i;
if(!prices) return 0;
for(i=1;i<pricesSize;i++){
    if(prices[i]>prices[i-1]) sum+=prices[i]-prices[i-1];
}
return sum;
}
```