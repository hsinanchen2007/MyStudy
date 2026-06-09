```python
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[0])
        end = float("-inf")
        ans = 0
        for x, y in intervals:
            if y > end:
                ans += 1
                end = y
        return ans
```
