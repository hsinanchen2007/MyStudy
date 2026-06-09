**状态空间：**
`currProfit[i]`为第`i`天卖出得到的最大利润
**初始化状态：**
`currProfit[1] = prices[2] - prices[1]` 当然，前提是至少要有两天的数据
**状态转移：**
若`currProfit[i - 1] <= 0`(第`i - 1`天卖出的利润为负数)，则在第`i`天，假设在前`(i - 1)`天亏损的基础上卖出，显然`currProfit[i]`一定不是最大的了，不如第`(i - 1)`天买入第`i`天的卖出
若`currProfit[i - 1] > 0`,第`i`天在前`(i - 1)`天盈利的基础上卖出，`currProfit[i]`一定是最大的
**结果的取值**
取`currProfit[i]`的最大值
**优化**
可以发现，`currProfit[i]`的值只与`currProfit[i-1]`有关，所以可以将数组变为单值，节省空间
**总结**
与“最大子序列和”思路相似

**代码如下**
```
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(0 == n || 1 == n) return 0;
        int profitMax = prices[1] - prices[0];
        int currProfit = prices[1] - prices[0];
        for(int i = 2; i < n; i++){ 
            currProfit = Math.max(currProfit, 0) + prices[i] - prices[i - 1];
            profitMax = Math.max(currProfit, profitMax);
        }
        return Math.max(profitMax, 0);

    }
}
```
**复杂度**
- 时间复杂度：O(n)
- 空间复杂度：O(1)