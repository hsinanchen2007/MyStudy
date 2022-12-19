### 一次遍历法:
遍历每天价格
用minprices记录当天是否为之前的最低价，然后用maxprofit来记录之后的价格差是否为最大利润。
p.s 这里有一个时间线的概念，很多人说如果最后一天是最低价怎么办其实是不对的，因为买入必须必卖出早。minpices记录的是相对之前的最低价即可。
时间复杂度O(n):一共就遍历一次，跟列表长度n有关
空间复杂度O(1):常数个变量
### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        minprices = int(1e9)
        maxprofit = 0
        for price in prices:
            maxprofit = max(price - minprices,maxprofit)
            minprices = min(price,minprices)
        return maxprofit
        
```
### 暴利循环法
双指针吧，超时了。i从左，j从右。
每一个i值时，j遍历整个列表找最大值
时间复杂度O(n^2)：
    i需要循环n-1次，j需要循环n-i-1次，相数是1，所以总共循环：（n-1+1）*(n-1)/2
空间复杂度O(1):只用了常数个变量
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        for i in range(len(prices)):
            for j in range(i + 1, len(prices)):
                ans = max(ans, prices[j] - prices[i])
        return ans
```