### 解题思路
此处撰写解题思路
先插入进去，再排序
### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        for i in range(len(intervals)):
            if intervals[i][0] > newInterval[0]:
                intervals.insert(i,newInterval)
                if i == 0:
                    return self.merge(intervals)
                else:
                    intervals = intervals[:i-1] + self.merge(intervals[i-1:])
                    return intervals

        intervals.insert(len(intervals),newInterval)
        intervals = intervals[:-2] + self.merge(intervals[-2:])
        return intervals

        
    
    def merge(self, intervals):
        if len(intervals) <= 1:
            return intervals

        i = 1
        while i < len(intervals):
            if intervals[i][1] <= intervals[i-1][1]:
                del intervals[i]
                #res.append(intervals[i-1])
            elif intervals[i][0] <= intervals[i - 1][1] < intervals[i][1]:
                intervals[i] = [intervals[i-1][0], intervals[i][1]]
                del intervals[i-1]
            else:
                i+=1

        
        return intervals
```