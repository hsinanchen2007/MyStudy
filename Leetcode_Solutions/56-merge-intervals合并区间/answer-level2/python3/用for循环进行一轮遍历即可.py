### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        if n <= 1:
            return intervals
        intervals.sort()
        b,re = 0,0
        for i in range(n):
            if i < n-1:
                if intervals[i-b+1][0] <= intervals[i-b][-1] <= intervals[i-b+1][-1]:
                    path = [intervals[i-b][0],intervals[i-b+1][-1]]
                    intervals.pop(i-b)
                    intervals.pop(i-b)
                    intervals.insert(i-b,path)
                    b += 1
                elif intervals[i-b][-1] >= intervals[i-b+1][0] and intervals[i-b+1][-1] < intervals[i-b][-1]:
                    intervals.pop(i-b+1)
                    b += 1
            else:
                break
        return intervals
```