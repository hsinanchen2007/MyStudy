
![Screen Shot 2020-02-15 at 4.32.45 PM.png](https://pic.leetcode-cn.com/0f844e7741597b178dd3f5126f2ff5a2a578bf20f868321c1fec64ba94b95c9f-Screen%20Shot%202020-02-15%20at%204.32.45%20PM.png)


### 解题思路

把股票每一天和前一天的价格差写成一个`差价数组`, 求买卖一次股票所能产生的最大收益相当于求这个`差价数组`的最大子数组, 因为在第 N 天买入第 M 天卖出得到的总收益就等于从 N 到 M 之间每天股票价格变化的总和. 

关于最大子数组的问题可以看看这道题: [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)

**关于Kadane算法**

最大子数组问题最早于1977年提出, 直到1984年卡内基梅隆大学的 Jay Kadane 才提出了该问题的线性算法.
更多细节详见维基百科[最大子数列问题](https://zh.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E5%88%97%E9%97%AE%E9%A2%98)

可以用动态规划的思路来理解Kadane算法:  

* 如果 max_here > 0，则说明 max_here 对截止当前元素的结果有增益效果，则 max_here 保留并加上当前遍历数字
* 如果 max_here <= 0，则说明 max_here 对截止当前元素的结果无增益效果，需要舍弃，则将 max_here 直接更新为当前遍历数字


将 `计算每日差价` 和 `Kadane算法` 写在一个迭代里后, 具体代码如下:

### 代码

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        prev = prices[0]
        max_profit = 0
        max_here = 0
        for t in prices[1:]:
            x = t - prev
            prev = t
            max_here = max_here + x if max_here > 0 else x
            max_profit = max(max_profit, max_here)
        return max_profit
```