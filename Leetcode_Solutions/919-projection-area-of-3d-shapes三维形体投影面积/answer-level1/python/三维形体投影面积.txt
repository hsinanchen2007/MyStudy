#### 方法：数学

**思路和算法**

从顶部看，由该形状生成的阴影将是网格中非零值的数目。

从侧面看，由该形状生成的阴影将是网格中每一行的最大值。

从前面看，由该形状生成的阴影将是网格中每一列的最大值。

**示例**

例如 `[[1,2],[3,4]]`：

* 顶部的阴影将为 4，因为网格中有四个非零值;

* 侧面的阴影为 `2 + 4`，因为第一行的最大值为 `2`，第二行的最大值为 `4`;

* 前面的阴影是 `3 + 4`，因为第一列的最大值是 `3`，第二列的最大值是 `4`。

```cpp [DoBY8EpQ-C++]
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int N = grid.size();
        int ans = 0;

        for (int i = 0; i < N;  ++i) {
            int bestRow = 0;  // largest of grid[i][j]
            int bestCol = 0;  // largest of grid[j][i]
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] > 0) ans++;  // top shadow
                bestRow = max(bestRow, grid[i][j]);
                bestCol = max(bestCol, grid[j][i]);
            }
            ans += bestRow + bestCol;
        }

        return ans;
    }
};
```
```java [DoBY8EpQ-Java]
class Solution {
    public int projectionArea(int[][] grid) {
        int N = grid.length;
        int ans = 0;

        for (int i = 0; i < N;  ++i) {
            int bestRow = 0;  // largest of grid[i][j]
            int bestCol = 0;  // largest of grid[j][i]
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] > 0) ans++;  // top shadow
                bestRow = Math.max(bestRow, grid[i][j]);
                bestCol = Math.max(bestCol, grid[j][i]);
            }
            ans += bestRow + bestCol;
        }

        return ans;
    }
}
```
```python [DoBY8EpQ-Python]
class Solution:
    def projectionArea(self, grid):
        N = len(grid)
        ans = 0

        for i in xrange(N):
            best_row = 0  # max of grid[i][j]
            best_col = 0  # max of grid[j][i]
            for j in xrange(N):
                if grid[i][j]: ans += 1  # top shadow
                best_row = max(best_row, grid[i][j])
                best_col = max(best_col, grid[j][i])

            ans += best_row + best_col

        return ans

        """ Alternative solution:
        ans = sum(map(max, grid))
        ans += sum(map(max, zip(*grid)))
        ans += sum(v > 0 for row in grid for v in row)
        """
```


**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是 `grid` 的长度。

* 空间复杂度：$O(1)$.