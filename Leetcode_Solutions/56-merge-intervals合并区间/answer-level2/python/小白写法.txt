### 解题思路
先sort排序，依次遍历合并区间，把合并过的移出列表，需要移出时，n要-1，以便temp1,temp2指向相合并的第二个列表

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        if len(intervals) > 0:
            temp1 = intervals[0][0]
            temp2 = intervals[0][1]
            n = 0
            for i in intervals[1:]:
                if i[0] <= temp2:
                    intervals[n + 1] = [temp1,max(i[1],temp2)]
                    intervals.pop(n)
                    n -= 1
                n += 1
                temp1 = intervals[n][0]
                temp2 = intervals[n][1]
            return intervals
        else:
            return []
```