Python 3
```
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if "0000" in deadends: return -1
        direction=[[1,0,0,0,1],[-1,0,0,0,1],[0,1,0,0,1],[0,-1,0,0,1],[0,0,1,0,1],[0,0,-1,0,1],[0,0,0,1,1],[0,0,0,-1,1]]
        position=[[0,0,0,0,0]]
        dead=set(deadends)
        while len(position)>0:
            for dire in direction:
                p=[(x+y)%10 for x,y in zip(dire,position[0])]
                p[4]=dire[4]+position[0][4]
                p_str="".join(list(map(str,p[:-1])))
                if p_str==target:return p[4]
                elif p_str not in dead:
                    position.append(p)
                    dead.add(p_str)
            position.pop(0)
        return -1
```
