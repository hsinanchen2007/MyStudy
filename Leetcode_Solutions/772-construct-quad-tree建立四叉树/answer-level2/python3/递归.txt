## 思路:

递归即可!

```python
class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        
        def is_leaf(grid, row, col):
            return all(grid[i][j] == grid[0][0] for i in range(row) for j in range(col))
        
        def dfs(grid):
            row = len(grid)
            col = len(grid[0])
            if is_leaf(grid, row, col):
                return Node(True if grid[0][0] else False, True, None, None, None, None)
            else:
                return Node('*', False,
                            dfs([row[:len(grid)//2] for row in grid[:len(grid)//2]]),
                            dfs([row[len(grid)//2:] for row in grid[:len(grid)//2]]),
                            dfs([row[:len(grid)//2] for row in grid[len(grid)//2:]]),
                            dfs([row[len(grid)//2:] for row in grid[len(grid)//2:]]))
            
        return dfs(grid)
```

当然用`numpy`切片更方便!

```python
class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        import numpy as np
        grid = np.array(grid)
       
        def is_leaf(grid, row, col):
            return all(grid[i][j] == grid[0][0] for i in range(row) for j in range(col))
        
        def dfs(grid):
            row = len(grid)
            col = len(grid[0])
            if is_leaf(grid, row, col):
                return Node(
                    grid[0][0] == 1,
                    True,
                    None,None,None,None
                )
            root = Node(
                    "*", False, None,None,None,None
            )
            root.topLeft = dfs(grid[:row//2,:col//2])
            root.topRight = dfs(grid[:row//2, col//2:])
            root.bottomLeft = dfs(grid[row//2:,:col//2])
            root.bottomRight = dfs(grid[row//2:, col//2:])
            return root
            
        return dfs(grid)
```

