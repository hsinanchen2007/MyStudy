### 解题思路
从0开始需要走很多重复的路，参考官方1解复杂度O(n^4)，卡到实例34了，先把当前能出发的位置写到queue里，然后这几个向外突围，走完queue后，才算是step+1，然后从新加如的queue中又开始突围

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        # 从陆地开始BFS  
        # 把陆地的索引拿出来
        n = len(grid)
        queue = [(x, y) for x in range(n) for y in range(n) if grid[x][y] == 1]
        step = -1
        while queue:
            for _ in range(len(queue)): 
                current = queue.pop(0)
                for i, j in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                    tx = current[0] + i 
                    ty = current[1] + j
                    if not (0 <= tx < len(grid) and 0 <= ty < len(grid[0])):
                        continue
                    elif grid[tx][ty] == 0:
                        grid[tx][ty] = -1
                        queue.append((tx, ty))
            step += 1
        return step if step else -1


```