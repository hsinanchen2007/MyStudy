```
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        l=set(map(tuple,obstacles))
        k=[[0,1],[1,0],[0,-1],[-1,0]]
        i=0
        o=[0,0]
        d=0
        for t in commands:
            if t==-1:i+=1            
            elif t==-2:i-=1
            else:
                for m in range(t):
                    h=[x+y*z for x,y,z in zip(o,k[i%4],[1,1])]
                    if tuple(h) in l:break
                    else:o=h
                d=max(d,o[0]**2+o[1]**2)
        return d
```
