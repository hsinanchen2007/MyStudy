### 解题思路
易理解直观的basecase

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        int days = prices.length;
        int[][] state = new int[days][2];
        // basecase
        state[0][0] = 0;
        state[0][1] = -prices[0];
        state[1][0] = Math.max(0, state[0][1] + prices[1]);
        state[1][1] = Math.max(-prices[0], state[0][0] - prices[1]);
        for (int i = 2; i < days; i++) {
            state[i][0] = Math.max(state[i - 1][0], state[i - 1][1] + prices[i]);
            state[i][1] = Math.max(state[i - 1][1], state[i - 2][0] - prices[i]);
        }
        return state[days - 1][0];
    }
}
```