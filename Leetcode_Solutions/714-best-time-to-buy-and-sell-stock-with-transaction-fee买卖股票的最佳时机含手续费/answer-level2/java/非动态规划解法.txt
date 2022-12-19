```
class Solution {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        if (n == 0) return 0;
        int min = prices[0], max = prices[0], ans = 0;
        for (int i=1; i<n; i++) {
            if (prices[i] > max) {
                max = prices[i];
            } else if (prices[i] < max - fee || prices[i] < min) {
                if (max - min > fee) ans += max - min - fee;
                min = max = prices[i];
            }
        }
        if (max - min > fee) ans += max - min -fee;
        return ans;
    }
}
```