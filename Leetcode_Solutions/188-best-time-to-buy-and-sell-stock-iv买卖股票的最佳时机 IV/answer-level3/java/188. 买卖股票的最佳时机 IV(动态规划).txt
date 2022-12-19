![image.png](https://pic.leetcode-cn.com/79d0edae6f20a6bff871c83909df620bb584037695b10053678f7bc6ab3dc5f2-image.png)

```
class Solution {
    public int maxProfit(int k, int[] prices) {
        int[] delta, dp, lastdp;
        int i, j, max, ans;

        if(prices.length < 2 || k == 0)
            return 0;
        delta = new int[prices.length];
        dp = new int[prices.length];
        lastdp = new int[prices.length];
        for(i = 1; i < prices.length; i++)
            delta[i] = prices[i] - prices[i-1];
        //计算出最多交易几次就能获得最大利润
        ans = 0;
        j = 0;
        for(i = 1; i < prices.length; i++){
            if(delta[i] >= 0)
                ans += delta[i];
            else
                j++;
        }
        //如果k过剩,直接返回最大值
        if(k > j)
            return ans;
        for(i = 1; i < prices.length; i++)
            dp[i] = delta[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
        for(j = 1; j < k; j++){
            for(i = 1; i < prices.length; i++)
                lastdp[i] = dp[i];
            max = lastdp[0];
            for(i = 1; i < prices.length; i++){
                dp[i] = delta[i] + (dp[i-1] > max ? dp[i-1] : max);
                max = lastdp[i] > max ? lastdp[i] : max;
            }
        }
        ans = dp[0];
        for(i = 1; i < prices.length; i++)
            ans = dp[i] > ans ? dp[i] : ans;
        return ans;
    }
}
```
