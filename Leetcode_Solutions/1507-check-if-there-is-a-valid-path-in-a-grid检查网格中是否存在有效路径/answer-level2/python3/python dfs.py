早上比赛的时候没有import
出现maximum recursion depth exceeded in comparison的错误了。

```
import sys
sys.setrecursionlimit(10000000)
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        mark=[[0]*len(grid[0]) for i in range(len(grid))]
        mark[0][0]=1
        nexts={1:[[0,1],[0,-1]],2:[[1,0],[-1,0]],3:[[0,-1],[1,0]],4:[[0,1],[1,0]],5:[[0,-1],[-1,0]],6:[[0,1],[-1,0]]}
        can={1:[1,3,4,5,6],2:[2,3,4,5,6],3:[1,2,4,5,6],4:[1,2,3,5,6],5:[1,2,3,4,6],6:[1,2,3,4,5]}
        
        def path(g,m,i,j):
            #print(i,j)
            if i==len(g)-1 and j==len(g[0])-1:
                return True
            if g[i][j] in [1,2,3,4,5,6]:
                next=nexts[g[i][j]]
                for n in next:
                    if 0<=i+n[0]<len(g) and 0<=j+n[1]<len(g[0]):
                        if m[i+n[0]][j+n[1]]==0 and g[i+n[0]][j+n[1]] in can[g[i][j]]:
                            m[i+n[0]][j+n[1]]=1
                            temp=path(g,m,i+n[0],j+n[1])
                            if temp:
                                return True
                return False
                            
            
        return path(grid,mark,0,0)
```
