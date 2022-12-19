#英文版比较好懂。
#find a water cell such that its distance to the nearest land cell is maximized and return the distance.
#找到一个海洋区域，这个海洋区域到与它最近的陆地区域的距离是最大的。
```
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:

        m=len(grid)
        n=len(grid[0])
        land=[]
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    land.append([i,j,0])
        
        if len(land) in [0,m*n]:return -1

        while land:
            node=land.pop(0)
            der=[[0,1],[1,0],[0,-1],[-1,0]]
            for i in der:
                if 0<=node[0]+i[0]<m and 0<=node[1]+i[1]<n and grid[node[0]+i[0]][node[1]+i[1]]==0:
                    grid[node[0]+i[0]][node[1]+i[1]]=1
                    land.append([node[0]+i[0],node[1]+i[1],node[2]+1])


        return node[2]
```
