```
class Solution:
    def earliestAcq(self, logs: List[List[int]], N: int) -> int:
        p=[i for i in range(N)]
        logs.sort(key=lambda x: x[0])

        def find(x, p):
            if x!=p[x]: return find(p[x], p)
            else: return p[x]
        
        for l in logs:
            p1, p2=find(l[1], p), find(l[2], p)
            if p1==p2: continue
            p[p1]=p2
            N-=1
            if N==1: return l[0]

        return -1
```

