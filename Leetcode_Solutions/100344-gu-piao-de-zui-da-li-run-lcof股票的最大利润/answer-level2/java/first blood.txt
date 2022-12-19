### 解题思路
此处撰写解题思路
取数组里面的递增最大值和最小值，并且保存上一次的最大利润。

### 代码

```java
class Solution {
    public static int maxProfit(int[] prices) {
        int minValue = 22222222;
        int maxValue = -999;
        int res = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] <  minValue) {
                minValue = prices[i];
                maxValue = prices[i];
            }
            maxValue = Math.max(maxValue,prices[i]);
            res = Math.max(res,maxValue - minValue);
        }
        return res;
    }
}
```