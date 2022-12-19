### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isCat(self, interval, newInterval):
        return not (interval[0]>newInterval[1] or interval[1]<newInterval[0])
    def catArea(self, interval, newInterval):        
        return [min(interval[0], newInterval[0]), max(interval[1],newInterval[1])] 
    def insert(self, intervals, newInterval):
        intervals.append(newInterval)
        for i in range(len(intervals)-1,0,-1):
            if intervals[i][0]>intervals[i-1][0]:
                break
            intervals[i],intervals[i-1] = intervals[i-1],intervals[i]     
            
        res = [intervals[0]]
        for i in range(1,len(intervals)):
            if self.isCat(res[-1], intervals[i]):
                res[-1] = self.catArea(res[-1], intervals[i])
            else:
                res.append(intervals[i])

        return res
```