### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def dfs(n,f,state):
            if n == 0:
                res.append(state)
            if f<n:
                dfs(n,f+1,state+"(")
            if f>0:
                dfs(n-1,f-1,state+")")
        dfs(n,0,"")
        return res




```