### 解题思路
与56题类似思想，57题仅在56题的基础上加上
`intervals.append(newInterval)`

### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        intervals.sort()
        res = []
        if not intervals:
            return res
        left = intervals[0][0]
        right = intervals[0][-1]
        for i in range(len(intervals)):
            list = intervals[i]
            if list[0] <= right:
                right = max(right, list[-1])
                continue
            else:
                res.append([left, right])
                left = list[0]
                right = list[1]
        res.append([left, right])
        print(res)
        return res
```