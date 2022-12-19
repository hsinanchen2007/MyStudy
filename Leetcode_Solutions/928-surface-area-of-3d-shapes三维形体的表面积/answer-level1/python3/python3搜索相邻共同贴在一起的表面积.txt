# 思路

1). 不考虑共同贴在一起的表面积，则**当前摞在一起的表面积 = 4 * 高度(grid[r][c]) + 2**；
2). **贴在一起的表面积 = 取自己和相邻的表面积的最小值 * 4个方向**
3). **结果= 1) - 2)**

# 代码
```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        # 计算相邻共同贴在一起的表面积
        def neighbour(r, c):
            sub_ngb = 0
            for nr, nc in ((r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)):
                if 0 <= nr < rows and 0 <= nc < cols:
                    sub_ngb += min(grid[r][c], grid[nr][nc])
            return sub_ngb
        ans = 0
        rows, cols = len(grid), len(grid[0])
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] != 0:
                    # 不考虑贴在一起的表面积 = 4 * 高度(grid[r][c]) + 2
                    # 表面积 = 不考虑贴在一起的表面积 - 贴在一起的表面积
                    ans += 4 * grid[r][c] + 2 - neighbour(r, c)
        return ans
```