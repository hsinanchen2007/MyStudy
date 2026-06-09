### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        self.res = set()

        def dfs(tmp,t_res):
            if not tmp:
                self.res.add(t_res)
                return
            for i,c in enumerate(tmp):
                dfs(tmp[:i]+tmp[i+1:],t_res+tmp[i])
                    

        dfs(s,"")

        return list(self.res)
    
    
    
    
    
```