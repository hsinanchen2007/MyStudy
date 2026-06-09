### 解题思路
贪心策略：每次选的区间的终点最小，后面就能有越多的区间


### 代码

```python
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        if len(intervals) < 2:
            return 0

        intervals.sort(key=lambda x:x[1])
        
        
        end = intervals[0][1]
        count = 0
        for j in range(1,len(intervals),1):
            if intervals[j][0] >= end:
                end = intervals[j][1]
                continue
            else:
                count += 1
                
        return count

```