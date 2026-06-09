慢都慢在解包了，解包的复杂度是O(n)，总复杂度是O(n+log(n))=O(n)，如果不解包的话，就得手写二分查找，总复杂度为O(log(n))。
```py
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        p = [*itertools.chain(*intervals)]                  #二维数组降维成一维数组
        x, y = newInterval
        l, r = bisect.bisect_left(p, x), bisect.bisect(p, y)#查找目标区间的左右插入点
        pl = p[l - 1] if l % 2 == 1 else x
        pr = p[r] if r % 2 == 1 else y                      #根据奇偶性确定插入区间的边界值
        return intervals[: l // 2] + [[pl, pr]] + intervals[(r + 1) // 2: ]#插入
```
