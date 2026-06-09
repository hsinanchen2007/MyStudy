### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
      //后一个减去前面的，算出获利最大的，取前面差值最大的
      if(prices.length == 0)return 0;
      int max = 0;
      for(int i = 0;i<prices.length;i++){
          for(int j=i+1;j<prices.length;j++){
             max = Math.max(max,prices[j]-prices[i]);   
          }
      }
      
    return max;
    }
}
```