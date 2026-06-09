```python
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # [1, 2], [2, 7], [3, 5], [4, 6]
        # [1, 2], [3, 5], [4, 6], [2, 7]
        # Greedy
        # Trade off:
        # Time complexity: O(NlogN)
        # Space complexity: O(N)
        if intervals == []: return 0
        intervals.sort(key = lambda x: x[0])
        res = 1
        endA, endB = intervals[0]
        for i in range(1, len(intervals)):
            a, b = intervals[i]
            if a >= endB:
                res += 1
                endA, endB = a, b
            elif b < endB:
                endA, endB = a, b
        return len(intervals) - res
```