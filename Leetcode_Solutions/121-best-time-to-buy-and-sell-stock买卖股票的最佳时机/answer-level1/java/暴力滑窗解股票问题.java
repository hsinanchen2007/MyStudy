### 解题思路
### 代码

```java
class Solution {
      public int maxProfit(int[] prices) {
        /*滑动窗口解股票问题*/
        int difference =  0;
        for (int i = 0; i <prices.length ; i++) {
            for (int j = i+1; j <prices.length ; j++) {
                if(prices[i]<prices[j]){
                    difference  = prices[j] - prices[i]>difference? prices[j] - prices[i]:difference;
                }
            }
        }
        return difference;
    }
}
```