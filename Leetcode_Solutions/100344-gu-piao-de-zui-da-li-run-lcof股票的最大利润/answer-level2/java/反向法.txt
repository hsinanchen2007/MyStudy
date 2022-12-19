### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxPrice = 0;
        int maxProfit = 0;
        for(int i = prices.length - 1;i >= 0;i--){
            if(prices[i] > maxPrice){
                maxPrice = prices[i];
            }
            if((maxPrice - prices[i]) > maxProfit){
                maxProfit = maxPrice - prices[i];
            }
        }
        return maxProfit;
    }
}
```