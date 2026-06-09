先排序，再合并。合并过程中维护两个变量curl和curr，表示当前区间的左右边界。

```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals: return []
        newint = sorted(intervals, key = lambda x: x[0])
        n = len(newint)
        if n == 1: return newint
        res = []
        curl, curr = newint[0][0], newint[0][1]
        for i in range(1, n):
            if curr < newint[i][0]:
                res.append([curl, curr])
                curl, curr = newint[i][0], newint[i][1]
            elif curr <= newint[i][1]:
                curr = newint[i][1]
        res.append([curl, curr])
        return res
```
