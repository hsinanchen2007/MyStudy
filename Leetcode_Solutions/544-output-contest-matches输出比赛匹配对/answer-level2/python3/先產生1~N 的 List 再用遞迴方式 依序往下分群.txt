### 解题思路
先產生1~N 的 List 再用遞迴方式 依序往下分群

### 代码

```python3
class Solution:
    def findContestMatch(self, n: int) -> str:

        com  = []
        for i in range(n):
            com.append(i+1)
        
        res = []
        def split(vec):
            nonlocal res
            if len(vec) == 2:
                res = tuple(vec)
                return
            com = []
            while len(vec) > 0:
                com.append((vec[0], vec[-1]))
                vec.pop(0)
                vec.pop(-1)
            split(com) 
            return 
              
        split(com)
        res = str(res).replace(" ","")  
        
        return res


            
```