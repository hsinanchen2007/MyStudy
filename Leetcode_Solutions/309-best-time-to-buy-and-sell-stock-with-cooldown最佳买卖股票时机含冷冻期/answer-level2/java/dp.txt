先写出状态转移方程，然后状态压缩减小空间复杂度。
```
class Solution {
    /**
    dp[i][0] = max{dp[i-1][0], dp[i-1][1]+price};
    dp[i][1] = max{dp[i-1][1], dp[i-2][0]-price};
    **/
    public int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;
        int rest = 0, preRest = 0, holder = Integer.MIN_VALUE;
        for (int price: prices) {
            int tmp = rest;
            rest = Math.max(rest, holder + price);
            holder = Math.max(holder, preRest - price);
            preRest = tmp;
        }
        return rest;
    }
}
```