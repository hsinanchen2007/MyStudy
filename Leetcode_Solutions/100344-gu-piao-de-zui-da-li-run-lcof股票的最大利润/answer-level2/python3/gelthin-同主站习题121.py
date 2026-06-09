### 解题思路
[主站 121 题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

当访问到 prices[i] 时，保存 min(prices[0:i])，然后两者相减，即是，在0-i-1 天某一天买入，在 i 天卖出所获得钱。
然后返回所获钱的最大值即可。



### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        current_min = prices[0]
        res = 0
        for i in range(1, len(prices)):
            res = max(prices[i]-current_min, res)
            current_min = min(current_min, prices[i])
        return res
```