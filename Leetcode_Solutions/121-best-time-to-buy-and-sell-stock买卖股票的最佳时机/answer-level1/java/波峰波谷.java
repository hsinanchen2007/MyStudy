### 解题思路
买入股票的时机，一定会在波谷出现，但不确定是哪一个。
卖出股票的时机，一定会在波峰出现，但不确定是哪一个。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        int min = Integer.MAX_VALUE;
        int profit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < min) {
                min = prices[i];
            } else if (prices[i] - min >= profit) {
                profit = prices[i] - min;
            }
        }
        return profit;
    }
}
```