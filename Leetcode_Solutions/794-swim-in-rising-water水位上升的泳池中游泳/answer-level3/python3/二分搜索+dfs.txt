### 解题思路
搜索范围是[0,数组最大值]，t时刻，用t替换数组中的最小值为t，然后从0,0开始深搜，看是否能够到达右下平台.

### 代码

```python3
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        import numpy as np
        grid = np.array(grid)
        row, col = grid.shape
        left = 0
        right = grid.max()

        seen = set()

        def dfs(i, j, array):
            if i == row - 1 and j == col - 1:
                return True

            for x, y in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                tmp_i = x + i
                tmp_j = y + j
                if 0 <= tmp_i < row and \
                        0 <= tmp_j < col and \
                        array[tmp_i][tmp_j] == array[i][j] and \
                        (tmp_i, tmp_j) not in seen:
                    seen.add((tmp_i, tmp_j))
                    if dfs(tmp_i, tmp_j, array):
                        return True

            return False

        while left < right:
            mid = (right + left) >> 1
            grid_copy = grid.copy()
            grid_copy[grid_copy < mid] = mid

            seen.clear()
            seen.add((0, 0))
            if dfs(0, 0, grid_copy):
                right = mid
            else:
                left = mid + 1
        return left

```