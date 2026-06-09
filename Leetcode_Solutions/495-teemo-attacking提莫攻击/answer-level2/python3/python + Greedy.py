```python
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        # 1, 2
        # array length <= 1,0000
        # Time complexity  : O(N)
        # Space complexity : O(N)
        begin, max_end, res = 0, 0, 0
        timeSeries.append(float('inf')) # dummy node
        for time in timeSeries:
            if time > max_end:
                res += max_end - begin
                begin = time
                max_end = time + duration
            else:
                max_end = max(max_end, time + duration)
        return res
```