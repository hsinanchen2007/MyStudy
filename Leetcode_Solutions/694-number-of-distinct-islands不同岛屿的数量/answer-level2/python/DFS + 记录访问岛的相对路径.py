### 解题思路
和找岛思路一致，但是难点是判断是否是同一个岛。
如果是同一个岛，那相同的DFS访问，访问路径是一样的， 那我们记录和左上角的相对路径就可以。
注意岛都是从左上角开始进入访问的。

#### 注意点
- 使用stack迭代，防止递归爆栈
- 进入岛，左上角当成(0,0),每访问岛的其他部分，就算出相对于左上角的坐标，记录到路径列表中
- 相同形状的岛会有相同的路径列表，以此来判断两个岛的形状是否是相同的

### 代码

```python
class Solution(object):
    def numDistinctIslands(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid: return 0
        height = len(grid)
        width = len(grid[0])
        shapes = []
        count = 0
        for i in range(height):
            for j in range(width):
                if grid[i][j] == 1: # found island
                    stack = [(i,j)]
                    shape = [(0,0)]
                    while stack:
                        x, y = stack.pop()
                        if x<0 or x >= height or y<0 or y>=width:
                            continue #越界，跳过
                        if grid[x][y] == 1:
                            shape.append((x-i,y-j)) #保存相对路径
                            grid[x][y] = 2 #标记被访问过 
                            stack.append((x-1, y))
                            stack.append((x+1, y))
                            stack.append((x, y-1))
                            stack.append((x, y+1))
                    if shape not in shapes:
                        shapes.append(shape)
                        count += 1
        return count

```