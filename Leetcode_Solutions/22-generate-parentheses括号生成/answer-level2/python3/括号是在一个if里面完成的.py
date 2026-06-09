### 解题思路
```

```
此处撰写解题思路

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def genHelper(l:int,r:int,temp:str):
            if n == 0:
                return
            if l==0 and r==0:
                res.append(temp)
            if l>r:
                return    
            if l>=0 and l <= r:
                genHelper(l-1, r, temp+'(')
                temp[:-1]
                genHelper(l, r-1, temp+')')
                temp[:-1]
        
        genHelper(n,n,'')
        return res
```