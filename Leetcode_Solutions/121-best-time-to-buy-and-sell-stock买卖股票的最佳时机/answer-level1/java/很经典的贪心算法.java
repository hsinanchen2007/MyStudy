### 解题思路
贪心算法，从左向右，维护一个最小值low，与每一天的股票价格做差，差最大的为答案

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxP = 0;
        int low = Integer.MAX_VALUE;
        for(int p : prices) {
            if(p < low) {
                low = p;
            }
            maxP = Math.max(maxP, p - low);
        }
        return maxP;
    }
}
```