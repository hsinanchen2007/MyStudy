![image.png](https://pic.leetcode-cn.com/a6f439e1ff82847849fbd3df75ad344408c945e58db556b1cc62ae957ca4903d-image.png)


```
'''
所有区间按照起点升序排列，从前到后扫描区间，并且维护已近扫过的区间的右边界的最大值
如果当前迭代区间的右边界小于已经扫过的区间的右边界最大值，当前区间就被前面区间包含
'''

from typing import List
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x: x[0])

        max_rbound = -1
        cnt = 0
        for interval in intervals:
            if interval[1] <= max_rbound:
                cnt += 1
            max_rbound = max(max_rbound, interval[1])
        return len(intervals) - cnt
```
