### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        intervals = sorted(intervals)
        i = 0
        while i < len(intervals):
            j = i+1
            while j < len(intervals):
                if intervals[i][1] >= intervals[j][0]:
                    intervals.insert(i, [min(intervals[i][0], intervals[j][0]), max(intervals[i][1], intervals[j][1])])
                    intervals.pop(i+1)
                    intervals.pop(j)
                    i -= 1
                    break
                j += 1
            i += 1
        return intervals
```