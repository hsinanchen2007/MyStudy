找到C的索引，S遍历跟它计算距离，选绝对值最小的

```
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        s=[]
        for i,v in enumerate(S):
            if v==C:
                s.append(i)
        r=[]      
        for i in range(len(S)):
            t=len(S)
            for j in s:
                t = min(t,abs(j-i))
            r.append(t)
        return r
```
