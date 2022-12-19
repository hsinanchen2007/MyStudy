#### 方法 1：暴力

**想法和算法**

分别检查每个 3x3 方格。对于每个方格，所有数字必须互不相同且在 1 到 9 之间；另外每行每列每条对角线的和必须相等。

**补充**

我们可以将判断 `if grid[r+1][c+1] != 5: continue` 加入我们的代码，这可以帮助我们快速跳出 `for r... for c...` 的循环。这是基于以下发现：

* 方格元素之和为 45，等于 1 到 9 的元素和。
* 每行每列的和最多为 15，因为三条这样的平行线等于整个方格之和。
* 对角线之和也为 15，由问题的定义可知。
* 将经过中心点的 4 条线所包含的 12 个值相加，和为 60；但总和也等于 45 加上三倍的中间值，这意味着中间点的值是 5。

```Java []
class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int R = grid.length, C = grid[0].length;
        int ans = 0;
        for (int r = 0; r < R-2; ++r)
            for (int c = 0; c < C-2; ++c) {
                if (grid[r+1][c+1] != 5) continue;  // optional skip
                if (magic(grid[r][c], grid[r][c+1], grid[r][c+2],
                          grid[r+1][c], grid[r+1][c+1], grid[r+1][c+2],
                          grid[r+2][c], grid[r+2][c+1], grid[r+2][c+2]))
                    ans++;
            }

        return ans;
    }

    public boolean magic(int... vals) {
        int[] count = new int[16];
        for (int v: vals) count[v]++;
        for (int v = 1; v <= 9; ++v)
            if (count[v] != 1)
                return false;

        return (vals[0] + vals[1] + vals[2] == 15 &&
                vals[3] + vals[4] + vals[5] == 15 &&
                vals[6] + vals[7] + vals[8] == 15 &&
                vals[0] + vals[3] + vals[6] == 15 &&
                vals[1] + vals[4] + vals[7] == 15 &&
                vals[2] + vals[5] + vals[8] == 15 &&
                vals[0] + vals[4] + vals[8] == 15 &&
                vals[2] + vals[4] + vals[6] == 15);
    }
}
```

```Python []
class Solution(object):
    def numMagicSquaresInside(self, grid):
        R, C = len(grid), len(grid[0])

        def magic(a,b,c,d,e,f,g,h,i):
            return (sorted([a,b,c,d,e,f,g,h,i]) == range(1, 10) and
                (a+b+c == d+e+f == g+h+i == a+d+g ==
                 b+e+h == c+f+i == a+e+i == c+e+g == 15))

        ans = 0
        for r in xrange(R-2):
            for c in xrange(C-2):
                if grid[r+1][c+1] != 5: continue  # optional skip
                if magic(grid[r][c], grid[r][c+1], grid[r][c+2],
                         grid[r+1][c], grid[r+1][c+1], grid[r+1][c+2],
                         grid[r+2][c], grid[r+2][c+1], grid[r+2][c+2]):
                    ans += 1
        return ans
```

**复杂度分析**

* 时间复杂度：$O(R*C)$，其中 $R,C$ 是 `grid` 的行数和列数。
* 空间复杂度：$O(1)$。