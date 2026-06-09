### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res=[]
        def backtrace(path,left,right,res):
            if left==0 and right==0:
                res.append(path)
                return 
            if left>0:backtrace(path+'(',left-1,right,res)
            if left<right:backtrace(path+')',left,right-1,res)
        backtrace('',n,n,res)
        return res


```