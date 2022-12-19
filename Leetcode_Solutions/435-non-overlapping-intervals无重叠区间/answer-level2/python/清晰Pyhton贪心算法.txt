### 代码

```python3
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals or not intervals[0]:
            return 0
        intervals.sort(key=lambda x:x[1])
        result = 0
        timePoint = intervals[0][0]
        for i in range(len(intervals)):
            if timePoint <= intervals[i][0]:
                result += 1
                timePoint = intervals[i][1]
        return len(intervals) - result

```