### 动态规划
基本思路：用两个变量，一个存储当前最大的收益，一个存储当前的最小值。用当前的卖出价值，减去前面的最小值，即为当前收益。空间复杂度比较好, O(l)，时间复杂度一般，应该是O(n)。一开始是用min函数找前面的最小值，超时了。代码如下：

```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n==0:
            return 0
        max_ = 0
        min_ = prices[0]
        for i in range(1,n):
            min_=min(min_, prices[i])
            t = prices[i]-min_
            max_= max(max_,t)
        return max_
```
