### 解题思路
dp[][],二维数组含义是第i次股票是否购买，
dp[i][0] 代表手里没存股票、dp[i - 1]代表手里有股票
于是乎：就有这样的动态方程
dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
dp[i][1] = Math.max(dp[i - 1][0] - prices[i], dp[i - 1][1]);

最后：当我求收益最大的时候，手里应该没有股票的。
所以遍历dp[i]**[0]**

//效率不是很高，应该可以在动态方程进行修改、压缩
//对于我这样基础不是很牢固的选手，上面这种动态方程易懂。奥里给！

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {        
        int len = prices.length;
        if (len == 0) return 0;
        int[][] dp = new int[len][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < len; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = Math.max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        }
        int max = dp[0][0];
        for (int i = 1; i < len; i++) {
            max = Math.max(dp[i][0], max);
        }

        return max;
    }
}
```