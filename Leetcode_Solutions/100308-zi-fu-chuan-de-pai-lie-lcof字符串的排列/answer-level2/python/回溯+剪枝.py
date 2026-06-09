### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        c,res = list(s),[]
        def dfs(x):
            if x==len(s)-1:
                res.append(''.join(c))
                return
            dic = set()
            for i in range(x,len(c)):
                if c[i] in dic:continue
                dic.add(c[i])
                c[i],c[x] = c[x],c[i]
                dfs(x+1)
                c[i],c[x] = c[x],c[i]
        dfs(0)
        return res
```