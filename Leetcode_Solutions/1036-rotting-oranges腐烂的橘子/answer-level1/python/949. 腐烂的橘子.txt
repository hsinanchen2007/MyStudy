### 解题思路
注意：
1、不是每个格子都遍历，而是顺着被标记成2的格子遍历，有种图的宽度优先搜索的意思
流程：
1、先做个预处理，看初始有多少个1，多少个2，把2的都加到队列里去
2、对于队列里的所有2，一旦弹出一个，就把这个感染的邻居加进去
3、直到没有橘子还能被感染或者队列已经为空了
4、用一个count标记新鲜橘子的数量，若最后还有新鲜橘子，返回-1.
### 代码

```python
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if grid == None:
            return
        row = len(grid)
        column = len(grid[0])
        queue = []
        count = 0
        for i in range(row):
            for j in range(column):
                if grid[i][j] == 1:
                    count = count + 1
                if grid[i][j] == 2:
                    queue.append((i,j))

        minute = 0
        while count>0 and len(queue)>0:
            minute = minute + 1
            n = len(queue)
            for k in range(n):
                i, j = queue.pop(0)
                if grid[i][j] == 2:
                    if i-1 >= 0 and grid[i-1][j] == 1:
                        grid[i-1][j] = 2
                        count=count-1
                        queue.append([i-1,j])
                    if j+1 < column and grid[i][j+1] == 1:
                        grid[i][j+1] = 2
                        count = count - 1
                        queue.append([i, j+1])
                    if i+1 < row and grid[i+1][j] == 1:
                        grid[i+1][j] = 2
                        count = count - 1
                        queue.append([i+1,j])
                    if j-1 >= 0 and grid[i][j-1] == 1:
                        grid[i][j-1] = 2
                        count = count - 1
                        queue.append([i,j-1])

            

        if count > 0:
            return -1
        else:
            return minute

```