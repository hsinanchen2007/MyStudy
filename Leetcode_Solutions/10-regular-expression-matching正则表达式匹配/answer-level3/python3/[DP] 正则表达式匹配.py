## 方法

- 首先判断是：动态规划里面的最长匹配问题
- 动态规划3步走：
  - 1. 确定状态：`d[i][j]`表示前i个s与前j个p匹配；比如`d[1][1]`指的是`s[:1]`与`p[:1]`匹配；
  - 2. 状态转移：
    - `s[i-1] == p[j-1]` or `p[j-1] == '.'`：
    - `p[j-1] == '*'`：可以看成：`x* -> ''` / `x* -> x` / `x* -> xx`
  - 3. 边界条件：
    - 需要考虑下 `d[0][j]`, 因为循环是从d[1][1]开始的；

## Solutions
```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        '''
        d[i][j]: s[:i] match p[:j]
        '''
        n_s, n_p = len(s), len(p)
        d = [[False] * (n_p+1) for ind in range(n_s+1)]
        if not n_p:
            if not n_s:
                return True
            else:
                return False
        d[0][0] = True
        for indp,cp in enumerate(p):
            if indp>0 and cp=='*':
                d[0][indp+1] = d[0][indp-1]

        for inds, cs in enumerate(s):
            for indp, cp in enumerate(p):
                if cs == cp or cp == '.':
                    d[inds+1][indp+1] = d[inds][indp]
                elif cp == '*':
                    if indp>0:
                        if (p[indp-1] == cs or p[indp-1] == '.'):
                            d[inds+1][indp+1] = d[inds][indp-1] or d[inds][indp+1] or d[inds+1][indp-1]
                        else:
                            d[inds+1][indp+1] = d[inds+1][indp-1]

        return d[n_s][n_p]
```