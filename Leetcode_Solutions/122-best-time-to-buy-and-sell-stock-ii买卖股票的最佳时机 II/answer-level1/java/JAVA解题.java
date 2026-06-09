### 解题思路
1、找到上升的最大值，遇到下降数据，累计上升了多大值；
2、重置上升数据的边界值；
3、重复步骤1，2；

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
    	if (prices.length < 2) {
    		return 0;
    	}
        int left = prices[0];
        int right = prices[0];
        int maxCount = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] <= right) {
                maxCount += right - left;
                left = prices[i];
            }
            right = prices[i];
        }
        maxCount += right - left;
        return maxCount;
    }
}
```