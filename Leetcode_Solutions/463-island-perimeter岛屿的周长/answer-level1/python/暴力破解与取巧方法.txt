### 解法一：暴力法

遍历数组中的每一个点，如果遇到岛屿，即 `grid[i][j] == 1` 时，判断该岛屿的上侧和左侧是否存在岛屿。

- 上侧存在且左侧存在：不加边数
- 上侧面或左侧只有一侧存在：边数 +2
- 上侧和左侧都不存在：边数 +4

```python
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        res = 0
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    if i == 0 and j == 0:
                        res += 4
                        continue
                    if i - 1 >= 0 and j - 1 >= 0:
                        if grid[i - 1][j] == 0 and grid[i][j - 1] == 0:
                            res += 4
                        elif grid[i - 1][j] ^ grid[i][j - 1] == 1:
                            res += 2
                    elif i - 1 < 0:
                        if grid[i][j - 1] == 1:
                            res += 2
                        else:
                            res += 4
                    elif j - 1 < 0:
                        if grid[i - 1][j] == 1:
                            res += 2
                        else:
                            res += 4
        
        return res
```

### 解法二：算周长

因为岛屿内部没有湖，所以本质上就是求一个矩形的周长。所以只要求出岛屿的上侧（或下侧）与左侧（或右侧）的长度和即可，再将该长度乘以 2。

```python []
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        res = 0
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    if i == 0 or grid[i - 1][j] == 0:
                        res += 1
                    if j == 0 or grid[i][j - 1] == 0:
                        res += 1
                        
        return res*2
```
```go []
func islandPerimeter(grid [][]int) int {
    var res = 0
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[0]); j++ {
            if grid[i][j] == 1 {
                if i == 0 || grid[i - 1][j] == 0 {
                    res += 1
                }
                if j == 0 || grid[i][j - 1] == 0 {
                    res += 1
                }
            }
        }
    }
    return res * 2
}
```