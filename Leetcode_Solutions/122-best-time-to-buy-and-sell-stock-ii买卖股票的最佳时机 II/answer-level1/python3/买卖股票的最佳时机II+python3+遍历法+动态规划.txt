### 解法1：遍历法
这题实际上就是求该数组中的递增子数组，然后把每一个递增子数组的最大值减去最小值，加到利润里面去就可以了，一遍遍历即可解决：
```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 实际上是要找出其中的递增子数组
        target = 0
        n = len(prices)
        i = 0
        while i<n-1:
            # 先求出递增子数组的起点
            while i<n-1:
                if prices[i+1]<prices[i]:
                    i += 1
                else:
                    break
            # 在接着这个起点求出递增子数组的终点
            j = i+1
            while j<n-1:
                if prices[j+1]>prices[j]:
                    j+=1
                else:
                    break
                    
            if j>n-1:  # 防止数组出现越界
                break
            # 盈利里面加上这一段的营收
            target += (prices[j]-prices[i])
            i = j+1
            
        return target
```
### 解法2：动态规划
换一种思路：只要第二天股票上升了，卖了就是赚了。实际上这种想法获得的利润跟上面的一样。基于这种想法，我们就可以写出状态转移方程：

 `dp[i] = dp[i-1] if prices[i]<=prices[i-1] else dp[i-1]+(prices[i]-prices[i-1])`

也就是说：如果今天比昨天价更高，则dp[i] = dp[i-1]+高出的价格；反之，则不变

代码如下：
```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # dp[i] = dp[i-1] if prices[i]<=prices[i-1] else dp[i-1]+(prices[i]-prices[i-1])
        res = 0
        for i in range(1,len(prices)):
            if prices[i]>prices[i-1]:
                res += (prices[i]-prices[i-1])
        return res
```
