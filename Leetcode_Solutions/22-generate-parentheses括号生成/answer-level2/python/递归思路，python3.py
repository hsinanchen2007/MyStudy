### 解题思路
此处撰写解题思路
递归思路，首先左右括号的数量肯定是n，所以我们只需根据左右括号的数量进行递归
即因为第一个括号肯定是左括号 可根据这一点无限递归自身下去，而条件就是括号数量减一

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        cur = ''
        def dfs(cur,left,right):
            if left==0 and right==0:
                ans.append(cur)
                return
            if right<left:
                return
            if left>0:
                dfs(cur +'(',left-1,right)
            if right>0:
                dfs(cur +')',left,right-1)
        dfs(cur,n,n)
        return ans
```