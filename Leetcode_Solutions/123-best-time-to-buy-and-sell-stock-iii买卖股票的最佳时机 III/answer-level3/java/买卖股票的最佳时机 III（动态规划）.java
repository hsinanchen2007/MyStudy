![image.png](https://pic.leetcode-cn.com/cf3dfe5446c4493cf27e71de9b04721f44dc122c176fb5f31b835a07b3528b7d-image.png)

```
//相当于求delta中的两个最大子序和
class Solution {
    public int maxProfit(int[] prices) {
        int[] dp1, dp2, delta;
        int i, ans, max;

        if(prices.length < 2)
            return 0;
        dp1 = new int[prices.length];
        dp2 = new int[prices.length];
        delta = new int[prices.length];
        for(i = 1; i < prices.length; i++)
            delta[i] = prices[i] - prices[i-1];
        for(i = 1; i < prices.length; i++)
            dp1[i] = delta[i] + (dp1[i-1] > 0 ? dp1[i-1] : 0);
        max = dp1[0];
        for(i = 1; i < prices.length; i++){
            dp2[i] = delta[i] + (max > dp2[i-1] ? max : dp2[i-1]);
            max = max > dp1[i] ? max : dp1[i];
        }
        ans = dp2[0];
        for(i = 1; i < prices.length; i++)
            ans = dp2[i] > ans ? dp2[i] : ans;
        return ans;
    }
}
```
