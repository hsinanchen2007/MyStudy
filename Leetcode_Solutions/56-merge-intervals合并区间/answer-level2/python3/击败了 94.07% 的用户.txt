### 解题思路
大致思路就是:

1. 先把List排序
2. 然后判断当前区间与上一个之间的关系

### 代码

```python3
class Solution:
    def merge(self, intervals):
        if len(intervals) <= 1:
            return intervals

        intervals.sort()
        print(intervals)
        i = 1

        while i < len(intervals):
            if intervals[i][1] <= intervals[i-1][1]:
                del intervals[i]
                #res.append(intervals[i-1])
            elif intervals[i][0] <= intervals[i - 1][1] < intervals[i][1]:
                intervals[i] = [intervals[i-1][0], intervals[i][1]]
                del intervals[i-1]
            else:
                i+= 1


        return intervals
```