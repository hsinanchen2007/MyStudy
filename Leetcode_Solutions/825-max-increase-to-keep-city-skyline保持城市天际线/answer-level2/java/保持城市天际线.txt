#### 方法一：计算行列限制

我们首先计算出天际线的值。显然，从顶部和底部看到的天际线是相同的，每一个位置的天际线高度是对应列的建筑物高度最大值，即 `col_maxes = [max(column_0), max(column_1), ...]`；从左侧和右侧看到的天际线也是相同的，每一个位置的天际线高度是对应行的建筑物高度最大值，即 `row_maxes = [max(row_0), max(row_1), ...]`。

对于 `grid` 中的每一个元素，我们可以将它增加到的最大高度为该元素行天际线与列天际线高度的较小值，即 `min(row_maxes[r], col_maxes[c])`。如果再增加高度，就会导致行天际线或列天际线中的至少一个发生变化。

由于 `grid` 中的每一个元素的高度增加都是独立的，因此我们贪心地把每一个元素都增加到最大值，就可以得到增加的最大总和。

```Java [sol1]
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int N = grid.length;
        int[] rowMaxes = new int[N];
        int[] colMaxes = new int[N];

        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c) {
                rowMaxes[r] = Math.max(rowMaxes[r], grid[r][c]);
                colMaxes[c] = Math.max(colMaxes[c], grid[r][c]);
        }

        int ans = 0;
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                ans += Math.min(rowMaxes[r], colMaxes[c]) - grid[r][c];

        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        row_maxes = [max(row) for row in grid]
        col_maxes = [max(col) for col in zip(*grid)]

        return sum(min(row_maxes[r], col_maxes[c]) - val
                   for r, row in enumerate(grid)
                   for c, val in enumerate(row))
```

**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是 `grid` 数组的边长。

* 空间复杂度：$O(N)$，用来存储行天际线和列天际线。