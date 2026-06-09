### 解题思路
贪心策略：按end排序后每次比较当前区间起始值是否大于等于前一区间的end值即可

### 代码

```python
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        res = 0
        intervals = sorted(intervals, key = lambda x:x[1])
        start = float('-inf')
        while intervals:
            if intervals[0][0] >= start:
                start = intervals.pop(0)[1]
            else:
                intervals.pop(0)
                res += 1
        return res
            
                

```