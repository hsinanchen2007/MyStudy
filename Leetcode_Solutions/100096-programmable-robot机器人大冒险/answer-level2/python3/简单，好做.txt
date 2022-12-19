```
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:        
        def canArrive(command,x,y):
            UCount=0
            RCount=0
            for c in command:
                if c=='U':
                    UCount+=1
                else:
                    RCount+=1
            n=min(x//RCount,y//UCount)
            x=x-n*RCount  
            y=y-n*UCount
            if x==0 and y==0:
                return True
            for c in command:
                if c=='U':
                    y-=1
                else:
                    x-=1
                if x==0 and y==0:
                    return True
                if x<0 or y<0:
                    return False
        tmp=[]
        for ob in obstacles:
            if (ob[0]<=x and ob[1]<y) or (ob[0]<x and ob[1]<=y):
                tmp.append([ob[0],ob[1]])
        for t in tmp:
            if canArrive(command,t[0],t[1]):
                return False
        return canArrive(command,x,y)
```