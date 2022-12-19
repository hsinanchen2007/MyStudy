
注意到：区间 [a, b] 对我们的 new 来说的话，如果 a > new[0] 或是 b < new[1] 的情况下，是不会受影响的。对于受影响的区间，我们就更新最小值left，最大值right。最终进行一个排序就可以了。

（时间击败98%，空间击败100%）

```python
class Solution(object):
    def insert(self, intervals, new):
        if not new: return intervals
        if not intervals: return new
        lst = []
        left = new[0]
        right = new[1]
        for i in intervals:
            if i[1] < new[0] or i[0] > new[1]:
                lst.append(i)
            else:
                left = min(i[0], left)
                right = max(i[1], right)
        lst.append([left, right])
        lst.sort()
        return lst
```