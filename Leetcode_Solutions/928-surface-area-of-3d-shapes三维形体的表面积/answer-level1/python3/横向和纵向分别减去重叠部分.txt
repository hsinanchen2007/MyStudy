### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
            def S_One_Place(num):
                if num <= 1:
                    return 6 * num
                else:
                    return 10 + (num - 2) * 4
            ans = 0
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    ans += S_One_Place(grid[i][j])
                    if j > 0:
                        ans -= min(grid[i][j], grid[i][j - 1]) * 2
                    if i > 0:
                        ans -= min(grid[i][j], grid[i - 1][j]) * 2

            return ans
```