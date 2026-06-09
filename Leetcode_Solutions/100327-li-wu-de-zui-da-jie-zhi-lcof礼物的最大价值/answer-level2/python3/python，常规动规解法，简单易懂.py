### 解题思路
每个位置的最大值等于左侧和上方的最大值加当前值，最后返回右下角的结果即可。

### 结果
![image.png](https://pic.leetcode-cn.com/6a733cce489451e4358822cc8aacd77d3b59ce398b21f0eafb99cba43dac3c78-image.png)

### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        for i in range(1, n):
            grid[0][i] += grid[0][i-1]
        for i in range(1, m):
            grid[i][0] += grid[i-1][0]
            for j in range(1,n):
                grid[i][j] += max(grid[i-1][j], grid[i][j-1])
        return grid[-1][-1]
```