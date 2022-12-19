### 解题思路
- 注意同一支股票可以当天卖出，当天买入；
- 相当于叠加效果，最后留下的是最佳方法；
- zip()方法产生的元素个数受到元素少的列表的约束；

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(j - i for i, j in zip(prices, prices[1:]) if j > i)
```