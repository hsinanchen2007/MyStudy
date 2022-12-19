```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # dp_pre_0 means dp[i-2][0]
        dp_pre_0, dp_i_0, dp_i_1 = 0, 0, float('-inf')

        for price in prices:
            tmp = dp_i_0
            dp_i_0 = max(dp_i_0, dp_i_1 + price)
            dp_i_1 = max(dp_i_1, dp_pre_0 - price)
            dp_pre_0 = tmp

        return dp_i_0
```
