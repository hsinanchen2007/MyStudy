### 解题思路
局部极小值以前的点得到的差值一定小于局部极小值处（左侧连续单调减），因此只需要找到所有该类点并找到后面的最大值即可

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l = len(prices)
        ms = 0
        for i in range(0, l - 1):
            if prices[i] >= prices[i + 1]:
                continue
            max_j = max(prices[i + 1:l])
            ms = max(ms, max_j - prices[i])
        return ms

```