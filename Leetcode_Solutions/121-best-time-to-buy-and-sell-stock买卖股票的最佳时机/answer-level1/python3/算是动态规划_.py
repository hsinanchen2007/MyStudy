### 解题思路
1. 记录当前的最小值
2. 记录当前的最大收益
3. 用后面的值减去最小值, 大于最大收益, 记录这个值, 不大于的话, 则记录之前的最大收益

### 代码

```python3
class Solution:
    def maxProfit(self, prices: list) -> int:
        if not prices:
            return 0
        counts = len(prices)
        benefits = list()
        benefits.append(0)
        cur_min = prices[0]
        for i in range(1, counts):
            cur_min = min(prices[i], cur_min)
            benefit = prices[i] - cur_min
            if benefit > benefits[i - 1]:
                benefits.append(benefit)
            else:
                benefits.append(benefits[i - 1])
        return benefits[counts-1]
```