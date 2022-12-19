### 解题思路
自己写的超时，主要是没有用Set和turtle
### 代码

```python3
class Solution(object):
    def robotSim(self, commands, obstacles):
    direction=[[0,1],[1,0],[0,-1],[-1,0]]
    dir=0
    pos=[0,0]
    ans=0
    for i in range(len(commands)):
                if commands[i]==-1:
                    dir= (dir+1) if dir<3 else 0
                elif commands[i]==-2:
                    dir= (dir-1) if dir>0 else 3
                else:
                        for j in range(commands[i]):
                            if [pos[0]+direction[dir][0],pos[1]+direction[dir][1]] in [num for num in obstacles]:
                                break
                            else:
                                pos[0],pos[1] = pos[0]+direction[dir][0],pos[1]+direction[dir][1]
                                ans=max(ans,pos[0]*pos[0]+pos[1]*pos[1])
```