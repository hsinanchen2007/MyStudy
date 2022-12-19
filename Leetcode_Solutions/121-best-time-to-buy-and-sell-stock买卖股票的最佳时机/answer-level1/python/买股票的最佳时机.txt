### 解题思路
该题可以用动态规划思想进行解决，解决思路如下：
原问题：列表中按照列表下标顺序寻找n个元素的最大差值（最小值在前，最大值在后）
子问题：列表中按照下标顺序求前n-1个元素的最大差值（最小值在前，最大值在后）
状态：第i个状态为前i个元素的最优解（最大利润）
边界：n=1 min_value = prices[0],max_value = 0
状态方程：
    max_value = max(max_value,prices[i]-min_value)
    min_value = min(min_value,prices[i])
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices :
            return 0
        min_value = prices[0]
        max_value = 0
        for i in range(1,len(prices)):
            max_value = max(max_value,prices[i]-min_value)
            min_value = min(min_value,prices[i])
        return max_value
```