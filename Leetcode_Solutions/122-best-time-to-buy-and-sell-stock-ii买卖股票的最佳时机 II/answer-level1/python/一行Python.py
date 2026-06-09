### 解题思路
其实很简单，一旦有赚立卖立买，这样所有赚钱机会都没错过。同一天卖买不影响结果。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum([prices[i] - prices[i-1] if prices[i] - prices[i-1] >0 else 0 for i in range(1, len(prices))])

```