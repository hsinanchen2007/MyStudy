### 解题思路
动态规划。 leftMin[i]记录着 i 之前所有的最小值 。 包含且以为i节点为尾巴的最大差值是 prices[i] - leftMin[i] ,求所有 prices[i] - leftMin[i] 的最小值 ，leftMin数组可以优化改为leftMin变量
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0)
            return 0 ;
        int ret = 0 ;
        int leftMin = prices[0] ;
        for (int i = 1 ; i < prices.length ; i++) {
            ret = Math.max(ret , prices[i] - leftMin ) ;
            leftMin = Math.min(leftMin ,prices[i]) ;
        }
        return ret ;
    }
}
```