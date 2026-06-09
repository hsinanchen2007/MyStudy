解题思路：直接做替换ans[c][r] = A[r][c]
代码：
```
class Solution(object):
    def transpose(self, A):
        ans = [[None] * len(A) for _ in range(len(A[0]))]
        for r, row in enumerate(A):
            for c, val in enumerate(row):
                ans[c][r] = val
        return ans
```
