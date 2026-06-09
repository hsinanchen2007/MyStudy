### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def dfs(left, right, s):
            if left == 0 and right == 0:
                res.append(s)
            if left > 0: dfs(left-1, right, s + '(')
            if right > left: dfs(left, right-1,  s + ')')
        dfs(n, n, '')
        return res
```