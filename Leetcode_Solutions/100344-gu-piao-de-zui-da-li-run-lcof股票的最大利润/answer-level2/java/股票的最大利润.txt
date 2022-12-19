### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length==0)return 0;
     int min=prices[0],max=-1;
     for(int i=0;i<prices.length;i++){
         if(prices[i]<min)
         min=prices[i];
        if(prices[i]-min>max)
        max=prices[i]-min;
     }
     return max;
    }
}
```