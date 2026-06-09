### 解题思路
此处撰写解题思路
左括号<n,添加(
右括号<左括号,添加)

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = set()


        def dfs(n:int,path:str,open:int,close:int,res:List[str]):
            if open+close==2*n:
                
                res.add(path)
                return 
            

            
            if open<n:
                dfs(n,path+'(',open+1,close,res)
            if open>close:
                dfs(n,path+')',open,close+1,res)
                

                
                

            pass

        dfs(n,'',0,0,res)
        return list(res)
```