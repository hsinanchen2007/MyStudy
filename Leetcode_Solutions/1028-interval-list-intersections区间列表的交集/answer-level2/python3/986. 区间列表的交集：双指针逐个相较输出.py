自己写的和官解基本没差，只是部分语法习惯不太一样，不过性能理论上不应该差这么多吧？

```py
class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        m, n = len(A), len(B)
        ans = []
        i, j = 0, 0
        while i < m and j < n:
            l, r = max(A[i][0], B[j][0]), min(A[i][1], B[j][1])#取交集
            if l <= r:
                ans += [[l, r]]     #交集不为空输出
            if A[i][1] < B[j][1]:   #区间的右边界更小就跳到下一个区间
                i += 1
            else:
                j += 1
        return ans
```
