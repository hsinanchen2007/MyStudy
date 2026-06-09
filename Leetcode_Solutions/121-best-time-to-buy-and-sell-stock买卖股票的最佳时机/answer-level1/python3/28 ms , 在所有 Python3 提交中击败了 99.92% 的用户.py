### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
      # 设置一个变量 记录最大利益
    max_benefit = 0
    # 最小的 买入价格 初始值为 int的最大值 因为列表可能为空 不设为列表的第一个元素为最大值
    min_price = sys.maxsize
    for price in  prices:
        # 若是当前元素 小于 设置的 最小买入价格 则最小买入价格 变为 当前元素
        if min_price > price:
            min_price = price
        # 若是 最大利益 小于 当前元素 和 最小买入价格 的差值 则最大利益等于这两个数字的差值
        elif max_benefit < (price - min_price):
            max_benefit = price - min_price
    return max_benefit
```