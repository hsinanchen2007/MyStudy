### 解题思路
最热题解大佬的帖子里面的basecase，很多人反馈难理解，易出错。
我这里的basecase更易看懂记住。

### 代码

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices == null || prices.length <= 1 || k < 1) {
            return 0;
        }
        if (k > prices.length / 2) {
            return maxProfit2(prices);
        }
        int days = prices.length;
        int[][][] state = new int[days][k + 1][2];
        // basecase
        for (int i = 0; i <= k; i++) {
            state[0][i][0] = 0;
            state[0][i][1] = -prices[0];
        }
        for (int i = 1; i < days; i++) {
            for (int j = 1; j <= k; j++) {
                state[i][j][0] = Math.max(state[i - 1][j][0], state[i - 1][j][1] + prices[i]);
                state[i][j][1] = Math.max(state[i - 1][j][1], state[i - 1][j - 1][0] - prices[i]);
            }
        }
        return state[days - 1][k][0];
    }

    public int maxProfit2(int[] prices) {
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        int days = prices.length;
        int[][] state = new int[days][2];
        state[0][0] = 0;
        state[0][1] = -prices[0];
        for (int i = 1; i < days; i++) {
            state[i][0] = Math.max(state[i - 1][0], state[i - 1][1] + prices[i]);
            state[i][1] = Math.max(state[i - 1][1], state[i - 1][0] - prices[i]);
        }
        return state[days - 1][0];
    }
}
```