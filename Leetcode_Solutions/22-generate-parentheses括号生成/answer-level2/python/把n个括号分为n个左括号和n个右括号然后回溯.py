### 解题思路
每次都可以从左括号或者右括号中选择一个加在现有的字符串中然后再回溯，结束条件是左右括号剩余数都为0

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res=[]
        def dfs(t,l,r):
            if l==r==0:
                res.append(t)
                return
            #只要还剩余左括号时，可以选择加左括号
            if l>0:
                dfs(t+'(',l-1,r)
            #当剩余的右括号比剩余的左括号多时，说明t中的左括号比右括号多，可以加右括号
            if r>l:
                dfs(t+')',l,r-1)
        dfs('',n,n)
        return res
```