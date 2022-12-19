### 解题思路
写一下具体流程：
（1）找出所有为2的点的坐标
（2）将所有点**同时**进行广度优先遍历并进行记录，包括将grid为1的点改为2,以及记录当前节点已经访问过
（3）获得最大深度max_depth
（4）判断还有没有为1的点，如果有返回-1，否则返回max_depth
之所以需要同时进行广度优先遍历，而不是一个一个点进行，举个例子就能理解，如[[1, 2, 1, 2, 1]]，如果两个为2的点分开进行广度优先遍历，则得到max_depth为3（根不算），这样就会有错误，所以同时进行广度有限遍历就是考虑到多个2对相连的1的影响。


### 代码

```python
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if grid == []:
            return -1
        len_1 = len(grid)
        len_2 = len(grid[0])
        bad = []
        mem = [[0] * len_2 for _ in range(len_1)] # 记录当前节点是否访问过
        # 找出所有为2的节点
        for i in range(len_1):
            for j in range(len_2):
                if grid[i][j] == 2:
                    bad.append((i, j))
        direct = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        def get_res(bad):
            if bad == []:
                return 0
            queue = []
            for x, y in bad:
                queue.append((x, y, 0))
                mem[x][y] = 1
            max_depth = 0
            while len(queue):
                x, y, depth = queue[0]
                for i, j in direct:
                    if x + i < 0 or x + i >= len_1 or y + j < 0 or y + j >= len_2 or mem[x + i][y + j] or grid[x + i][y + j] == 0:
                        continue
                    queue.append((x + i, y + j, depth + 1)) 
                    grid[x + i][y + j] = 2
                    mem[x + i][y + j] = 1
                    if depth + 1 > max_depth:
                        max_depth = depth + 1
                del queue[0]
            return max_depth
        max_day = get_res(bad)
        print(grid)
        for i in range(len_1):
            for j in range(len_2):
                if grid[i][j] == 1:
                    return -1
        return max_day
```