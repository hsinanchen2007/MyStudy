# BFS
建立一个四个方向的字典，保存某个方向的能连接的方向编号
right = {1:[1,3,5],4:[1,3,5], 6:[1,3,5]}
以right 为例，1的右边只能是1，3，5，但是2不与右边相连，所以2不在字典内
在bfs的过程中，进行如下判断：
1. 坐标是否有效
2. 当前坐标是否有这个方向
3. 下一个坐标是否于当前坐标相连
4. 下一个坐标是否已经遍历

若在遍历过程中当前坐标为右下角坐标，则返回True，否则结束遍历后返回False

```
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        right = {1:[1,3,5],4:[1,3,5], 6:[1,3,5]}
        left = {1:[1,4,6], 3:[1,4,6], 5:[1,4,6]}
        up = {2:[2,3,4],5:[2,3,4],6:[2,3,4]}
        down = {2:[2,5,6],3:[2,5,6],4:[2,5,6]}

        queue = [[0,0]]
        m = len(grid)
        n = len(grid[0])
        visited = set((0,0))
        while queue:
            size = len(queue)
            while size:
                node = queue.pop(0)
                x, y = node[0], node[1]
                # print(x,y)
                if x == m-1 and y == n-1:
                    return True
                # right
                if y+1<n and grid[x][y] in right and grid[x][y+1] in right[grid[x][y]] and (x, y+1) not in visited:
                    queue.append([x, y+1])
                    visited.add((x, y+1))
                # left
                if y-1>=0 and grid[x][y] in left and grid[x][y-1] in left[grid[x][y]] and (x, y-1) not in visited:
                    queue.append([x, y-1])
                    visited.add((x, y-1))
                # up
                if x-1>=0 and grid[x][y] in up and grid[x-1][y] in up[grid[x][y]] and (x-1, y) not in visited:
                    queue.append([x-1, y])
                    visited.add((x-1, y))
                # down
                if x+1<m and grid[x][y] in down and grid[x+1][y] in down[grid[x][y]] and (x+1, y) not in visited:
                    queue.append([x+1, y])
                    visited.add((x+1, y))
                size-=1
        return False
```
