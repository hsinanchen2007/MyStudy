### 解题思路
如题

### 代码

```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        n=len(s)
        used=[False for _ in range(n)]
        res=[]
        def dfs(s,char):
            if len(char)==len(s):
                res.append(char)
                return 
            visited=[] # 同层相同元素不能dfs
            for i in range(n):
                if not used[i] and s[i] not in visited:
                    used[i]=True
                    dfs(s,char+s[i]) # 这里会有新的visited
                    used[i]=False
                    visited.append(s[i])
        dfs(s,'')
        return res

```