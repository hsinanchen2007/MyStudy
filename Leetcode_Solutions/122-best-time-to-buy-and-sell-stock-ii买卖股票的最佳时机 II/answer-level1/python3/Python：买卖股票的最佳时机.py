### 解题思路
其实就是叠加上升阶段每两天的利润

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(prices[i]-prices[i-1] for i in range(1,len(prices)) if prices[i]-prices[i-1]>0)
```