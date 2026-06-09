### 解题思路
> 依次遍历，记录当前最小价格，实时计算当前最大收益；

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        '''
        执行用时 :44 ms, 在所有 Python3 提交中击败了88.43%的用户
        内存消耗 :14.5 MB, 在所有 Python3 提交中击败了10.53%的用户
        '''
        if not prices:
            return 0
        lowest = prices[0]
        ans = 0
        for i in range(1, len(prices)):
            diff = prices[i] - lowest
            if diff > ans:
                ans = diff
            if prices[i] < lowest:
                lowest = prices[i]
        return ans
```