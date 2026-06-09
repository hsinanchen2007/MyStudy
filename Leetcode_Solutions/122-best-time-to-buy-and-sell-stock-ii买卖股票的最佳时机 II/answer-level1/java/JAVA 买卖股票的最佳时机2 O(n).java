思路 ：只要遇见后一天的 价格比前一天的价格高  就将差值加入到利润里面

```
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int res = 0;
        if (n <= 1) {
            return 0;
        }
        for (int i = 0; i < n - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }
}
```
