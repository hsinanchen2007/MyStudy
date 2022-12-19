### BFS
执行用时 :104 ms, 在所有 Python3 提交中击败了69.42%的用户
内存消耗 :19.9 MB, 在所有 Python3 提交中击败了5.05%的用户

思路：
1. 维护一个marked集合，存放已经被判断过是陆地还是岛屿(i, j)对
2. 找到靠近左上方的第一个不在marked中的值得“1”的位置(a, b)，以此为根节点进行BFS
    BFS过程中marked不断增加
    当队列为空的时候说明与根节点相临的所有点被找到，即发现了一个岛屿
3. 重复上一个过程，直到不存在不在marked中的值得“1”的位置
### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        marked = set()
        queue = deque()
        cnt = 0

        for a in range(len(grid)):
            for b in range(len(grid[0])):
                if (a, b) not in marked and grid[a][b] == '1':
                    # print('seed:', a, b)
                    queue.append((a, b))
                    marked.add((a, b))

                    # 扫描上下左右
                    while queue:
                        # print(queue)
                        i, j = queue.popleft()

                        if i - 1 >= 0 and (i - 1, j) not in marked:
                            if grid[i - 1][j] == '1':
                                queue.append((i - 1, j))
                            marked.add((i - 1, j))
                        if j - 1 >= 0 and (i, j - 1) not in marked:
                            if grid[i][j - 1] == '1':
                                queue.append((i, j - 1))
                            marked.add((i, j - 1))
                        if i + 1 < len(grid) and (i + 1, j) not in marked:
                            if grid[i + 1][j] == '1':
                                queue.append((i + 1, j))
                            marked.add((i + 1, j))
                        if j + 1 < len(grid[0]) and (i, j + 1) not in marked:
                            if grid[i][j + 1] == '1':
                                queue.append((i, j + 1))
                            marked.add((i, j + 1))

                        if not queue:
                            cnt += 1
                            # print('cnt:', cnt)

        return cnt
```

### DFS
递归

### 代码
``` python3
class Solution:
    def dfs(self, inputs):
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while self.stk:
            node = self.stk.pop()
            for direction in directions:
                row, col = node[0]+direction[0], node[1]+direction[1]
                if (row, col) not in self.seen and 0 <= row < len(inputs) and 0 <= col < len(inputs[0]) and inputs[row][col] == '1':
                    self.seen.add((row, col))
                    self.stk.append((row, col))
        self.cnt += 1

    def numIslands(self, grid: List[List[str]]) -> int:
        self.cnt = 0
        self.stk = []
        self.seen = set()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (i, j) not in self.seen and grid[i][j] == '1':
                    self.stk.append((i, j))
                    self.seen.add((i, j))
                    self.dfs(grid)
        return self.cnt
```