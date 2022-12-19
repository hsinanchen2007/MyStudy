### 解题思路
这一题印象深刻，是2017年南京大学计算机机试题，当时没分数。
循环后最后一次中间结果经常忘了加，一定要小心。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if (n==0) or (n==1):
            return 0
        if n==2:
            if prices[0] < prices[1]:
                return prices[1]-prices[0]
            else:
                return 0
        result = 0
        current_min = prices[0]
        pre = prices[0]
        for x in prices[1:]:
            if x <= pre:
                result += pre - current_min
                current_min = x
                pre = x
            if x > pre:
                pre = x
        # 最后一次经常忘了加
        result += pre - current_min
        return result
            
```