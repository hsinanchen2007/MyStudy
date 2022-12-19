```
# -*- coding: utf-8 -*-
def dfs(res, left, right, tmp, n):
    if left == n and right == n:
        res.append(tmp)
    if left > right:
        dfs(res, left, right + 1, tmp + ')', n)
    if left < n:
        dfs(res, left + 1, right, tmp + '(', n)


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        left = 0
        right = 0
        res = []
        tmp = ""
        dfs(res, left, right, tmp, n)
        return res
```
