### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        if not prices :
            return 0
        # 大概,更新最下值 和更新最大值的思路
        # 更新最小值：是更新i前面的最小值，就是最低股票的价格
        # 更新最大值是：最高股票减去最最低股票的值
        
        # 第一个作为最小值
        minp=prices[0]
        maxs=0
        for i in range(1,n):
            maxs=max(maxs,prices[i]-minp)
            minp=min(minp,prices[i])

        return maxs
```