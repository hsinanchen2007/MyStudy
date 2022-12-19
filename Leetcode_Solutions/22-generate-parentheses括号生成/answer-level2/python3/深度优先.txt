### 解题思路
深度优先算法，直接看代码

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(s):
            if len(s) == 2 * n:
                res.append(s)
            else:
                if s.count('(') < n:
                    dfs(s + '(')
                if s.count(')') < n and s.count(')') < s.count('('):
                    dfs(s + ')')

        res = []
        dfs('')
        return res
```