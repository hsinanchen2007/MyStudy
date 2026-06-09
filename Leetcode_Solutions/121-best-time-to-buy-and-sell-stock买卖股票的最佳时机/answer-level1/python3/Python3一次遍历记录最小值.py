### 解题思路
只需要遍历一次，就是记录最小值的时候要更新最大值

### 代码

```python3
class Solution:
    def maxProfit(self, prices):
        if prices == []:
            return 0
        length = len(prices)
        res = 0
        min_num = float('inf')
        for i in range(length - 1):
            if prices[i] < prices[i + 1]:
                if prices[i] < min_num:
                    min_num = prices[i]
                max_num = prices[i + 1]
                res = max(max_num - min_num, res)
        return res
```