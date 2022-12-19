### 思路一：

暴力

我们需要找出给定数组中两个数字之间的最大差值（即，最大利润）。此外，第二个数字（卖出价格）必须大于第一个数字（买入价格）。

### 代码：

时间复杂度O(n^2)，空间复杂度O(1)

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2) {
            return 0;
        }
        int maxProfit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }
}
```

### Result：

Runtime：360ms

Your runtime beats 7.47% of java submissions.

### 思路二：

只需要遍历一次数组，用一个变量记录遍历过数中（截止到当前第i天）的最小值，然后每次计算当前值和这个最小值之间的差值最为利润 **（因为买入必须在卖出之前）**，然后每次选较大的利润来更新。当遍历完成后当前利润即为所求。

### 代码：

时间复杂度O(n)，空间复杂度O(1)

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2) {
            return 0;
        }
        int maxProfit = 0;
        int buyCost = Integer.MAX_VALUE;
        for (int i = 0; i < prices.length; i++) {
            buyCost = Math.min(prices[i], buyCost);
            maxProfit = Math.max(maxProfit, prices[i] - buyCost);
        }
        return maxProfit;
    }
}
```

### Result：

Runtime：2ms

Your runtime beats 60.96% of java submissions.