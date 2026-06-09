### 解题思路
1）第i天卖出时，要达到利润最大只需要求解[0,i-1]最低的股票价格就可以了。
2）基于1得到第i天的最大收益为,f(i) = prices(i) - min(i-1) 
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0){
            return 0;
        }
        int minxPrice = prices[0];
        int maxPrice = 0 ;
        for (int i=0;i<prices.length;i++){
            if (prices[i] < minxPrice){
                minxPrice = prices[i];
            }
            if (prices[i] -minxPrice > maxPrice){
                maxPrice = prices[i] -minxPrice;
            }
        }
        return maxPrice;
    }
}
```
时间复杂度:O(n)
空间复杂度：O(1)