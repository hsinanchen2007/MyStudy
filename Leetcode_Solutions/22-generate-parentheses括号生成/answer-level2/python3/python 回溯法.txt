### 解题思路
回溯法，记录一下可用"(" 和“）”的个数，在递归时候进行判断即可

### 代码

```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res=[]
        def helper(ans,pre,last):
            if  pre==0 and last==0:
                res.append(ans)
                return
            if pre>0:
                helper(ans+"(",pre-1,last)
            if last>0 and last>pre:
                helper(ans+")",pre,last-1)
        helper("",n,n)
        return res
        print(res)
            

       
```