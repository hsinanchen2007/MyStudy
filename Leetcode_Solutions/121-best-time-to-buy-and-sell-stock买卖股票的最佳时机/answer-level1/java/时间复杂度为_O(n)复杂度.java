### 解题思路

刚开始比较担心的一点是最低点不一定是最大利润处，发现按照这种做法，minprice可能会变化，但是maxprofit不会随着一起变化。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int minprice = Integer.MAX_VALUE;
        int maxprofit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;



    }
}
```