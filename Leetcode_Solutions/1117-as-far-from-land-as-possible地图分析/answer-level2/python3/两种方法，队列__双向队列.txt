### 解题思路
大陆填海，思路见代码

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        from collections import deque
        length = len(grid)
        res = -1
# solution2：利用双向队列，每次popleft()
        queue = deque()
        for i in range(length):
            for j in range(length):
                if grid[i][j] == 1:
                    queue.append((i, j))
# solution1：利用队列
        # queue = [(i, j) for i in range(length) for j in range(length) if grid[i][j] == 1]
        if len(queue) == 0 or len(queue) == length ** 2: return -1
        while queue:
            for _ in range(len(queue)):
                x, y = queue.popleft()
                for xi, yi in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]:
                    if xi >= 0 and xi < length and yi >= 0 and yi < length and grid[xi][yi] == 0:
                        queue.append((xi, yi))
                        grid[xi][yi] = -1
            res += 1
        return res
```