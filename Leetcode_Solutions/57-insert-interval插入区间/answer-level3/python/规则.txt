### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        if not intervals:
            return [newInterval]
        if not newInterval:
            return intervals
        is_in = False
        for interval in intervals:
            if interval[1]<newInterval[0]:
                res.append(interval)
            elif interval[1]<=newInterval[1]:
                newInterval[0] = min(interval[0], newInterval[0])
            elif interval[0]<=newInterval[1]:
                newInterval[0] = min(newInterval[0], interval[0])
                newInterval[1] = max(newInterval[1], interval[1])
            elif interval[0]>newInterval[1] and not is_in:
                res.append(newInterval)
                res.append(interval)
                is_in = True
            else:
                res.append(interval)
        if not is_in:
            res.append(newInterval)
        return res
```