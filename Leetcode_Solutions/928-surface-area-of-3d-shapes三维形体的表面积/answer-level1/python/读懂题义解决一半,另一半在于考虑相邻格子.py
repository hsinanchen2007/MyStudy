### 解题思路

思路还是比较简单的
	就是分别计算每个格子的贡献,再叠加所有格的贡献即可..

	每个格都会贡献上下两个面+2
	侧面要和4个相邻的格子比较,如果比相邻的大则v-nv,至少为0

核心代码是 ans += max(0,grid[r][c]-nv)
 for r_,c_ in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
		if r_<0 or r_>n-1 or c_<0 or c_>n-1:
			nv =0
		else:
			nv = grid[r_][c_]
#还有就是遍历四个格子,越界则0反之则读取对应的v,高度


### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans = 0
        for r in range(n):
            for c in range(n):
                if grid[r][c]:
                    ans += 2
                    for r_,c_ in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
                        if r_<0 or r_>n-1 or c_<0 or c_>n-1:
                            nv =0
                        else:
                            nv = grid[r_][c_]
                        ans += max(0,grid[r][c]-nv)
        return ans
```