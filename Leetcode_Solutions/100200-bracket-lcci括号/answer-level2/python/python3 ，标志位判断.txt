### 解题思路
此处撰写解题思路

说递归也是可以的啊
n代表f的最大值，f<n 就可以选择 '(' 选择 '(' 说明 f+=1
f>0 就可以选择 ')' 选择')' 说明 n-=1 f-=1

当n==0 说明匹配完成了。

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        ans = []
        def helper(n,f=0,res=''):
            if n==0:
                ans.append(res)
            if f<n:
                helper(n,f+1,res+'(')
            if f>0:
                helper(n-1,f-1,res+')')
        
        helper(n)
        return ans


            

```