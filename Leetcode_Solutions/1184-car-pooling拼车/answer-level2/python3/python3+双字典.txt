### 解题思路
双字典

### 代码

```python3
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        start = {}
        end = {}
        min_start = -1
        max_end = 1001
        for i in range(len(trips)):
            min_start = min(min_start, trips[i][1])
            max_end = max(max_end, trips[i][2])
            if trips[i][1] not in start:
                start[trips[i][1]] = trips[i][0]
            else:
                start[trips[i][1]] += trips[i][0]
            if trips[i][2] not in end:
                end[trips[i][2]] = trips[i][0]
            else:
                end[trips[i][2]] += trips[i][0]
        count = 0
        for i in range(min_start, max_end):
            count = count + start.get(i,0) - end.get(i,0)
            if count > capacity:
                return False
        return True
```