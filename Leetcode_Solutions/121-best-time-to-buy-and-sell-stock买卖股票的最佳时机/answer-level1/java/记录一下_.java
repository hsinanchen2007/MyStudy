### 解题思路
(1)当前的骨片股票只能在之后才能出售
(2) 最小股票值标记：将股票的出售按最小价格划分阶段
(3) 每出现一个比前一个最小价格更小的价格，就将该价格后面产生的最高利润与前面阶段产生的最高利润比较
(4) 按阶段更新最高利润

### 代码

```java

class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE;
        int maxPrf = 0;
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxPrf) {
                maxPrf = price - minPrice;
            }
        }
        return maxPrf;
    }
}
```