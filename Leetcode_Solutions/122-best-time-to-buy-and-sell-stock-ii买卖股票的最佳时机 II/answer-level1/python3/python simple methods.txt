### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        '''
        profit = 0
        for i in range(len(prices)-1):
            tmp = prices[i]-prices[i-1]
            if tmp>0: profit+=tmp
        return profit
        '''

        '''
        return sum(b-a for a,b in zip(prices,prices[1:]) if b>a)
        '''

        maxprofit = 0
        for i in range(len(prices)-1):
            maxprofit += max(0,prices[i+1]-prices[i])
        return maxprofit
```