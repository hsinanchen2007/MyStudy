![image.png](https://pic.leetcode-cn.com/fbc904bbe6fb31b7a1bb769a2b55ac654248d93ba147146e77abde1a5f110c24-image.png)
```
class Solution {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        if (n == 1) return 0;
        int min = prices[0], max = prices[0];
        int ans = 0;
        for (int price: prices) {
            if (price >= max) {
                max = price;
            } else if (price < min || price < max-fee) {
                if (max-min>fee)
                    ans += max-min-fee;
                min = price;
                max = price;
            }
        }
        if (max-min>fee)
            ans += max-min-fee;
        return ans;
    }
}
```



