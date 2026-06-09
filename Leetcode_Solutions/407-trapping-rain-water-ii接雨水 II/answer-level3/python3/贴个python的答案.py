```
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        import heapq
        if not heightMap:return 0
        q = []#小顶堆
        row = len(heightMap)
        col = len(heightMap[0])
        if row<3 or col<3:return 0
        visited = [[False]*col for _ in range(row)]
        for i in range(row):#第一列最后一列入堆
            heapq.heappush(q,(heightMap[i][0],(i,0)))
            visited[i][0] = True
            heapq.heappush(q,(heightMap[i][col-1],(i,col-1)))
            visited[i][col-1] = True
        for j in range(1,col-1):
            heapq.heappush(q,(heightMap[0][j],(0,j)))
            visited[0][j] = True
            heapq.heappush(q,(heightMap[row-1][j],(row-1,j)))
            visited[row-1][j]=True
        d = [[0,1],[0,-1],[1,0],[-1,0]]
        res = 0
        while q:
            h,(x,y) = heapq.heappop(q)
            #print(h,x,y)
            for i in range(4):
                newx = x+d[i][0]
                newy = y+d[i][1]
                if 0<=newx<row and 0<=newy<col and visited[newx][newy]==False:
                    newh = heightMap[newx][newy]
                    if newh<h:
                        res += h-newh
                        heightMap[newx][newy] = h
                    heapq.heappush(q,(heightMap[newx][newy],(newx,newy)))
                    visited[newx][newy] = True
        return res
```
