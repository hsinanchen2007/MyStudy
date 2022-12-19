
```python []
class Solution:
    def generateParenthesis(self, n):
        if not n:
            return []
        self.res = []
        self.dfs(n, n, '')
        return self.res

    def dfs(self, l, r, item):
        if l > r:
            return
        if not l and not r:
            self.res.append(item)
        if l > 0:
            self.dfs(l - 1, r, item + '(')
        if r > 0:
            self.dfs(l, r - 1, item + ')')
```

