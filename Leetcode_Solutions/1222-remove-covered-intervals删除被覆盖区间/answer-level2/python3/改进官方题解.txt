### 解题思路
`rmax = max(rmax, intervals[i][1])`没必要
Python 多关键字排序

### 代码

```python
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        n = len(intervals)
        intervals.sort(key=lambda u:(u[0],-u[1]))
        ans,cur_rmax = n,intervals[0][1]
        for i in range(1,n):
            if intervals[i][1] <= cur_rmax:
                ans-=1
            else:
                cur_rmax = intervals[i][1]
        return ans

```