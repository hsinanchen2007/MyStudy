```python
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        # ballons at most 10 ** 4
        # most overlaps
        # [2, 8] => [2, 8], [1, 6], [7, 12]
        #[1, 6] . [7, 12]
        #[2, 8] . [10, 16]
        if points == []: return 0
        points.sort(key = lambda x: x[0])
        end = float('-inf')
        ans = 0
        for point in points:
            if point[0] <= end:
                end = min(end, point[1])
            else:
                ans += 1
                end = point[1]
        return ans
```