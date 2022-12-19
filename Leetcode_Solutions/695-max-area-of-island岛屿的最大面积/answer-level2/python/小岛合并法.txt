### 解题思路

看评论，大家基本都是官方的思路，把自己的思路写出来供大家参考。

岛屿合并法，找出每个面积是1的小岛，然后根据不同小岛之间的连接，合并成最大的岛屿。
最后找出其中最大的一个

### 代码

```python
class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        
        r=  len(grid)
        islands=[]
        edges  = []
        if r ==0:
            return 0
        c = len(grid[0])
        for i in grid:
            i.append(0)
        grid.append([0]*c)
        ans = 0 
        for i in range(r-1, -1, -1):
            for j in range(c-1, -1, -1):
                if  grid[i][j] ==1:
                    island=[[i,j]]
                    islands.append(island)
                    grid[i][j]=len(islands)
                    if grid[i+1][j]>0:
                        edges.append([[i,j],[i+1,j]])
                    if grid[i][j+1]>0:
                        edges.append([[i,j],[i,j+1]])
        if len(islands)>0:
            ans = 1
        while len(edges)>0:
            edge= edges.pop()
            newislandid = grid[edge[0][0]][edge[0][1]]-1
            oldislandid = grid[edge[1][0]][edge[1][1]]-1
            if newislandid == oldislandid:
                continue
            if len(islands[newislandid])<len(islands[oldislandid]):
                newislandid,oldislandid=oldislandid,newislandid
            for i in islands[oldislandid]:
                grid[i[0]][i[1]]=newislandid+1
                islands[newislandid].append(i)
            islands[oldislandid]=[]
            if ans<len(islands[newislandid]):
                ans = len(islands[newislandid])
     
        return ans
```