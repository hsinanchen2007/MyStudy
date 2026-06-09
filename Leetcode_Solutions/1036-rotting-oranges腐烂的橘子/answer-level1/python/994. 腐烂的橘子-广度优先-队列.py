### 解题思路
    # 执行用时 :36 ms, 在所有 Python 提交中击败了88.14%的用户
    # 内存消耗 :11.7 MB, 在所有 Python 提交中击败了72.00%的用户

第一步 找到所有腐烂橘子
第二步：
    # 依次弹出腐烂的橘子(current level)
    # 找出当前橘子能够腐烂的所有其它橘子(next level)
    # 将这些腐烂的橘子和对应的level加入队列
    # 重复以上步骤直到清空队列
第三步：
    # if 如果格子里还有新鲜橘子返回-1
    # 返回max level， 即时间

### 代码

```python
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row, col, time = len(grid), len(grid[0]), 0
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        queue = []
        queue = [(i, j, time) for i in range(row) for j in range(col) if grid[i][j] == 2]

        while queue:
            i, j, time = queue.pop(0)
            for di, dj in directions:
                if 0 <= i + di < row and 0 <= j + dj < col and grid[i + di][j + dj] == 1:
                    grid[i + di][j + dj] = 2  # 腐烂
                    queue.append((i + di, j + dj, time + 1)) 
        
        for row in grid:
            if 1 in row:
                return -1
        return time