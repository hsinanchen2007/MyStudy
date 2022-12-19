# 不改变原有数组顺序

```python
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        size = len(intervals)
        indexes = [i for i in range(size)]
        indexes.sort(key=lambda i: intervals[i][0])

        def firstGreater(target: int) -> int:
            if target > intervals[indexes[-1]][0]:
                return -1

            l, r = 0, size - 1
            while l < r:
                mid = (l + r) >> 1
                if intervals[indexes[mid]][0] < target:
                    l = mid + 1
                else:
                    r = mid
            return indexes[l]

        return [firstGreater(intervals[i][1]) for i in range(size)]
```