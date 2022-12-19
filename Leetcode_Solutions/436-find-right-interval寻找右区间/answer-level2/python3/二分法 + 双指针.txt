## 思路:

思路一：二分法

把左边界提取出来排序，这样通过二分法找第一个大于等于右边界的数。

思路二：双指针

分别对左右边界进行排序，可以快速找到右边界下一个右侧区间。

## 代码:

思路一：

```python
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        import bisect
        res = []
        loc = []
        for idx, val in enumerate(intervals):
            loc.append([val[0], idx])
        loc.sort()
        for _, right in intervals:
            l = bisect.bisect_left(loc, [right])
            if l >= len(loc):
                res.append(-1)
            else:
                res.append(loc[l][1])
        return res
```

思路二：

```python
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        intervals = [tuple(interval) for interval in intervals]
        res = [-1] * n
        loc = {}
        for idx, val in enumerate(intervals):
            loc[val] = idx
        left_sort = sorted(intervals)
        right_sort = sorted(intervals, key=lambda x: x[1])
        i = 0
        j = 0
        # print(left_sort, right_sort)
        while i < n:
            while j < n and right_sort[j][1] <= left_sort[i][0]:
                res[loc[right_sort[j]]] = loc[left_sort[i]] 
                j += 1
            else:
                i += 1
        return res
```

