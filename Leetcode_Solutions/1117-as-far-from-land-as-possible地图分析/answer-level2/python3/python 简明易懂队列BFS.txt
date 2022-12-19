1. 设定方向向量，顺序为上下左右
2. 申请一个空队列
3. 遍历全部的区域，将所有陆地的坐标入队
4. 查看如果全部为陆地或没有陆地则返回-1
5. BFS扩散，循环至队列为空
6. 扩散过程中，每次从队列中取出一个坐标，这个坐标为陆地或已遍历过的海洋
7. 对这个坐标进行四次扩散（上下左右），若扩散到的节点有出边界或被遍历过或是陆地，则返回循环
8. 若没有，则将该点的数值在出发点的基础上+1，坐标入队
9. 循环结束后，返回最后一个出队的坐标，此时坐标对应的数值即为最远距离

```
from queue import Queue
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        if len(grid)==0 or len(grid[0])==0:
            return -1
        # 方向向量
        xdr = [0,0,-1,1]
        ydr = [1,-1,0,0]
        q = Queue(len(grid)*len(grid))
        # 将陆地入栈
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]==1:
                    q.put((i,j))
        # 如果没有陆地或没有海洋
        if q.empty() or q.full():
            return -1
        # BFS扩散
        while not q.empty():
            point = q.get()
            x, y = point[0], point[1]
            for k in range(4):
                nx = x + xdr[k]
                ny = y + ydr[k]
                # 如果扩散超出边界或遇到陆地或遇到被遍历过的海洋则不做记录重新循环
                if nx<0 or nx>=len(grid) or ny<0 or ny>=len(grid) or grid[nx][ny]!=0:
                    continue
                # 如果遇到海洋则将海洋在出发点的基础上加1以记录距离
                grid[nx][ny] = grid[x][y] + 1
                q.put((nx,ny))
```
