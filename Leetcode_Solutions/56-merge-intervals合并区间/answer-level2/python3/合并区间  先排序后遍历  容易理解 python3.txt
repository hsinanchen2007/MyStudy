### 解题思路
方法理解起来比较直观，不过效率不高


首先对区间进行排序
如果第i个区间的头等于第i+1个区间的头，直接删除第i个区间
如果第i个区间的头大于第i+1个区间的头，则判断第i个区间的尾是否小于第i+1个区间的头:
1. 如果是，继续遍历
2. 否则删除第i+1个区间之后，再对第i个区间重新赋值`intervals[i] = [intervals[i][0], max(intervals[i+1][1], intervals[i][1])]`
### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        i = 0
        while i < len(intervals)-1:
            if intervals[i][0] == intervals[i+1][0]:
                del intervals[i]
                continue
            else:
                if intervals[i+1][0] > intervals[i][1]:
                    i += 1
                    continue
                else:
                    temp = [intervals[i][0], max(intervals[i+1][1], intervals[i][1])]
                    intervals.pop(i+1)
                    intervals[i] = temp
                    continue
        return intervals

```