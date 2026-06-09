### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals=sorted(intervals,key=lambda x:x[0])
        n=len(intervals)
        for i in range(1,n):
            if intervals[i-1][0] <= intervals[i][0] and intervals[i-1][1] >= intervals[i][0]:
                if intervals[i-1][1] < intervals[i][1]:
                    intervals[i][0]=intervals[i-1][0]
                    intervals[i-1]=0
                else:
                    intervals[i][1]=intervals[i-1][1]
                    intervals[i][0]=intervals[i-1][0]
                    intervals[i-1]=0
                continue
            if intervals[i-1][0] == intervals[i][0] and intervals[i-1][1] == intervals[i][1]:
                intervals[i-1]=0
        m=intervals.count(0)
        for i in range(m):
            intervals.remove(0)
        return intervals


```