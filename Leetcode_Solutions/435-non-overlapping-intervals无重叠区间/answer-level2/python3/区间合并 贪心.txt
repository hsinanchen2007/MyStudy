### 解题思路
按end排序后, 计数那些start在上一个区间的end前的区间个数就行了

### 代码

```python3
class Solution:
    def eraseOverlapIntervals(self, intervals) -> int:
        if not intervals: return 0
        from functools import cmp_to_key # 这个会造成时间长
        def cmp(a, b):
            return a[1]-b[1]
            # if a[1]<b[1]: return -1
            # else: return 1
            # elif a[1]>b[1]: return 1
            # else:
            #     if a[0]<b[0]: return -1
            #     else: return 1
        intervals = sorted(intervals, key=cmp_to_key(cmp)) # 直接用lambda x: x[1]更快
        # print(intervals)
        tmp, res = intervals[0], 0
        for i in range(1, len(intervals)):
            if intervals[i][0]>=tmp[1]: tmp = intervals[i]
            else: res += 1
        return res
```