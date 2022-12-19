### 解题思路
思路一：朴素想法
- 维护一个最小值（初始为列表第一个元素），维护一个最大收益（初始为0）
- 向后查找，如果有更小的值，更新minimum;时刻记得维护最大值更新
思路二：动态规划
- i天最大收益等于max(i-1天最大收益，i天最大收益)，即max(maximum,prices[i]-minimum)

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices)<=1:
            return 0
        minimum=prices[0]
        maximum=0    
        for i in range(1,len(prices)):
            maximum = max(maximum,prices[i]-minimum)
            minimum = min(minimum,prices[i])
        return maximum
```