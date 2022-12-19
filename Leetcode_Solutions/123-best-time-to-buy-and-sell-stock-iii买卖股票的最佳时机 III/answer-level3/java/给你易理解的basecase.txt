### 解题思路
最热题解的大佬的basecase很多人反馈不好理解，很容易写错。
我这个易理解，更直观，效果一样。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        int days = prices.length;
        int times = 2;
        int[][][] state = new int[days][times + 1][2];
        state[0][0][1] = 0;
        state[0][0][0] = 0;
        state[0][1][1] = -prices[0];
        state[0][1][0] = 0;
        state[0][2][1] = -prices[0];
        state[0][2][0] = 0;
        for (int i = 1; i < days; i++) {
            for (int k = 1; k <= times; k++) {
                state[i][k][0] = Math.max(state[i - 1][k][0], state[i - 1][k][1] + prices[i]);
                state[i][k][1] = Math.max(state[i - 1][k][1], state[i - 1][k - 1][0] - prices[i]);
            }
        }
        return state[days - 1][times][0];
    }
}
```