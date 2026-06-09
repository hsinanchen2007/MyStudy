### 解题思路
思路清奇。。。。
### 代码

```c
int maxProfit(int* prices, int pricesSize){
  int sum=0,i;
  for(i=1;i<pricesSize;i++)
    if(prices[i]>prices[i-1])sum+=prices[i]-prices[i-1];
    return sum;  
}
```