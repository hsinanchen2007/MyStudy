### 解题思路

只需要定义两个变量：今天之前可以获得的股票最大利润，以及今天之前的最低价格。遍历更新这两个变量即可。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;
        int maxBeforeToday = 0;
        int smallest = prices[0];
        for (int i = 1; i < prices.length; i++) {
            maxBeforeToday = Math.max(maxBeforeToday, prices[i] - smallest);
            if (prices[i] < smallest) smallest = prices[i];
        }
        return maxBeforeToday;
    }
}
```