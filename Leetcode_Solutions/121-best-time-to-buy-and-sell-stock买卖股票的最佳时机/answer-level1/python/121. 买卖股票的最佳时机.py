# 1. DP - 1 转为最大子序列问题
https://leetcode-cn.com/problems/maximum-subarray/

1.1 思路
- 一次遍历就知道 从min - max点的差值
- 例如 [1,5,3,6], 两个数据差值为 [4, -2, 3] 最大子序列值为 min = 1 max = 6, 其实是 4 + -2 + 3
- 我们将A -> B -> C 问题转为 C - A = (C - B) + (B - A)

1.2 详解
- _max值 是当前子序列最大值; 注意这里有业务前提, 求得最小值如果为负数, 返回为0；
- _max值 不可以和_tmp混淆, _max是存目前最大值, _tmp是连续值, 只有连续最大值才有意义, 不可以_max + tmp 或者 _max + prices[i]
- _tmp连续值暂存处, 我们要保证是差值list是连续的, 同时也需要知道是否暂存当前连续值

```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        _len = len(prices)
        if _len < 2: return 0

        _max = max(prices[1] - prices[0], 0)
        tmp = _max
        for i in range(1, _len - 1):
            R = prices[i + 1] - prices[i]
            _max = max(0, tmp, tmp + R, _max, R)
            tmp = max(tmp + R, R)
        return _max
```


# 2. DP - 2
最大值 - 最小值 & 最大值是在最小值的后面 (题中有时间和顺序问题)
2.1 思路
- 最小值 买入, 找最小值 _min
- 最大值 卖出, 且按照业务规则, 卖出需要在买入之后
- 找到最小值很容易, 遍历一遍即可找到, 卖出的最大值: max(_max, price[i] - min)

```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # 可以是连续求解问题, 但是重点是, 
        # 1. 找到当前 买入的最小值 _min
        # 2. 收入最大值, 且需要对比 当前值 - _min, 因为每次都需要确认的是 小的值在list左侧, 大的值在list右侧
        # 3. _max
        if not prices: return 0
        _max, _min = 0, prices[0]
        for i in prices:
            _max = max(_max, i - _min)
            _min = min(_min, i)
        return _max
```