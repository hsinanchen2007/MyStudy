####  方法一：贪心算法[Wrong Answer]
我们先找到一条樱桃最多的路径走到右下角，然后摘下樱桃，再从摘完后的樱桃地找到最多的樱桃路径返回，摘下樱桃。

但是在下面的情况，就会找不到最佳的答案：

```
11100
00101
10100
00100
00111
```

**算法：**
- 我们可以使用动态规划来计算从任何位置 `(i, j)` 到右下角最多能摘到的樱桃数 `dp[i][j]`。这和[最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)非常相似，如果不熟悉这类问题，请参阅链接。
- 然后，我们可以找到从左上角到右下角可以摘到最多樱桃的路径，通过我们计算的 `dp` 来判断我们移动的方向，基于比较 `dp[i+1][j]` 和 `dp[i][j+1]`。
- 我们将樱桃摘下以后，再从右下角到左上角做相同的策略。最终能摘到的樱桃数量就是答案。

```Python [ ] 
class Solution(object):
    def cherryPickup(self, grid):
        def bestpath(grid):
            N = len(grid)
            NINF = float('-inf')
            dp = [[NINF] * N for _ in xrange(N)]
            dp[-1][-1] = grid[-1][-1]
            for i in xrange(N-1, -1, -1):
                for j in xrange(N-1, -1, -1):
                    if grid[i][j] >= 0 and (i != N-1 or j != N-1):
                        dp[i][j] = max(dp[i+1][j] if i+1 < N else NINF,
                                       dp[i][j+1] if j+1 < N else NINF)
                        dp[i][j] += grid[i][j]

            if dp[0][0] < 0: return None
            ans = [(0, 0)]
            i = j = 0
            while i != N-1 or j != N-1:
                if j+1 == N or i+1 < N and dp[i+1][j] >= dp[i][j+1]:
                    i += 1
                else:
                    j += 1
                ans.append((i, j))
            return ans

        ans = 0
        path = bestpath(grid)
        if path is None: return 0

        for i, j in path:
            ans += grid[i][j]
            grid[i][j] = 0

        for i, j in bestpath(grid):
            ans += grid[i][j]

        return ans
```

```Java [ ]
class Solution {
    public int cherryPickup(int[][] grid) {
        int ans = 0;
        int[][] path = bestPath(grid);
        if (path == null) return 0;
        for (int[] step: path) {
            ans += grid[step[0]][step[1]];
            grid[step[0]][step[1]] = 0;
        }

        for (int[] step: bestPath(grid))
            ans += grid[step[0]][step[1]];

        return ans;
    }

    public int[][] bestPath(int[][] grid) {
        int N = grid.length;
        int[][] dp = new int[N][N];
        for (int[] row: dp) Arrays.fill(row, Integer.MIN_VALUE);
        dp[N-1][N-1] = grid[N-1][N-1];
        for (int i = N-1; i >= 0; --i) {
            for (int j = N-1; j >= 0; --j) {
                if (grid[i][j] >= 0 && (i != N-1 || j != N-1)) {
                    dp[i][j] = Math.max(i+1 < N ? dp[i+1][j] : Integer.MIN_VALUE,
                                        j+1 < N ? dp[i][j+1] : Integer.MIN_VALUE);
                    dp[i][j] += grid[i][j];
                }
            }
        }
        if (dp[0][0] < 0) return null;
        int[][] ans = new int[2*N - 1][2];
        int i = 0, j = 0, t = 0;
        while (i != N-1 || j != N-1) {
            if (j+1 == N || i+1 < N && dp[i+1][j] >= dp[i][j+1]) i++;
            else j++;

            ans[t][0] = i;
            ans[t][1] = j;
            t++;
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$。其中  $N$ 是 `grid` 的长度。
* 空间复杂度：$O(N^2)$，`dp` 数组所使用的空间


####  方法二：动态规划（自顶向下）[Accepted]
- 与其从左上角走到右下角，再从右下角走到左上角；不如直接考虑从左上角选两条路走到右下角。
- 在走了 `t` 步之后，我们可能处于的位置 `(r, c)` 满足 `r+c=t`，所以如果我们在位置 `(r1, c1)` 和 `(r2, c2)` 有两个人，那么 `r2=r1+c1-c2`。这意味着` r1，c1，c2` 唯一地决定了两个走了 `t` 步数的人。这个条件让我们能够很好地进行动态规划。

**算法：**
- 定义 `dp[r1][c1][c2]` 是两个人从 `(r1, c1)` 和 `(r2, c2)` 开始，朝着 `(N-1, N-1)` 所能摘到最多的樱桃数量，其中 `r2=r1+c1-c2`。
- 如果 `grid[r1][c1]` 和 `grid[r2][c2]` 不是荆棘，那么 `dp[r1][c1][c2]` 的值是 `(grid[r1][c1] + grid[r2][c2])`，加上 `dp[r1+1][c1][c2]`，`dp[r1][c1+1][c2]`，`dp[r1+1][c1][c2+1]`，`dp[r1][c1+1][c2+1]` 的最大值。在 `(r1, c1) == (r2, c2)` 的情况下，我们要避免重复计数。
- 为什么要加上 `dp[r+1][c1][c2]`，`dp[r1][c1+1][c2]`，`dp[r1+1][c1][c2+1]`，`dp[r1][c1+1][c2+1]`的最大值？它对应 1 号和人 2 号向下或向右移动的 4 种可能性：
	- 1 号向下和 2 号向下：`dp[r1+1][c1][c2]`；
	- 1 号向右和 2 号向下：`dp[r1][c1+1][c2]`
	- 1 号向下和 2 号向右：`dp[r1+1][c1][c2+1]`
	- 1 号向右和 2 号向右：`dp[r1][c1+1][c2+1]`

```Python [ ]
class Solution(object):
    def cherryPickup(self, grid):
        N = len(grid)
        memo = [[[None] * N for _1 in xrange(N)] for _2 in xrange(N)]
        def dp(r1, c1, c2):
            r2 = r1 + c1 - c2
            if (N == r1 or N == r2 or N == c1 or N == c2 or
                    grid[r1][c1] == -1 or grid[r2][c2] == -1):
                return float('-inf')
            elif r1 == c1 == N-1:
                return grid[r1][c1]
            elif memo[r1][c1][c2] is not None:
                return memo[r1][c1][c2]
            else:
                ans = grid[r1][c1] + (c1 != c2) * grid[r2][c2]
                ans += max(dp(r1, c1+1, c2+1), dp(r1+1, c1, c2+1),
                           dp(r1, c1+1, c2), dp(r1+1, c1, c2))

            memo[r1][c1][c2] = ans
            return ans

        return max(0, dp(0, 0, 0))
```

```Java [ ]
class Solution {
    int[][][] memo;
    int[][] grid;
    int N;
    public int cherryPickup(int[][] grid) {
        this.grid = grid;
        N = grid.length;
        memo = new int[N][N][N];
        for (int[][] layer: memo)
            for (int[] row: layer)
                Arrays.fill(row, Integer.MIN_VALUE);
        return Math.max(0, dp(0, 0, 0));
    }
    public int dp(int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;
        if (N == r1 || N == r2 || N == c1 || N == c2 ||
                grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -999999;        
        } else if (r1 == N-1 && c1 == N-1) {
            return grid[r1][c1];
        } else if (memo[r1][c1][c2] != Integer.MIN_VALUE) {
            return memo[r1][c1][c2];
        } else {
            int ans = grid[r1][c1];
            if (c1 != c2) ans += grid[r2][c2];
            ans += Math.max(Math.max(dp(r1, c1+1, c2+1), dp(r1+1, c1, c2+1)),
                            Math.max(dp(r1, c1+1, c2), dp(r1+1, c1, c2)));
            memo[r1][c1][c2] = ans;
            return ans;
        }
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^3)$。其中 $N$ 是 `grid` 的长度，动态规划有 $O(N^3)$ 的状态。
* 空间复杂度：$O(N^3)$，`memo` 所使用的空间。


####  方法三：动态规划（自底向上）[Accepted]
假设 `r1+c1=t` 是第 `t` 层。因为递归只能引用下一层，所以我们一次需要在内存中保留两层。

**算法：**
在第 `t` 步，`dp[c1][c2]` 为两个人从 `(0, 0)` 到 `(r1, c1)` 和 `(0, 0)` 到 `(r2, c2)` 能摘到最多樱桃的数量，其中 `r1 = t-c1, r2 = t-c2`。我们的动态规划类似于方法 2。

```Python [ ]
class Solution(object):
    def cherryPickup(self, grid):
        N = len(grid)
        dp = [[float('-inf')] * N for _ in xrange(N)]
        dp[0][0] = grid[0][0]
        for t in xrange(1, 2*N - 1):
            dp2 = [[float('-inf')] * N for _ in xrange(N)]
            for i in xrange(max(0, t-(N-1)), min(N-1, t) + 1):
                for j in xrange(max(0, t-(N-1)), min(N-1, t) + 1):
                    if grid[i][t-i] == -1 or grid[j][t-j] == -1:
                        continue
                    val = grid[i][t-i]
                    if i != j: val += grid[j][t-j]
                    dp2[i][j] = max(dp[pi][pj] + val
                                    for pi in (i-1, i) for pj in (j-1, j)
                                    if pi >= 0 and pj >= 0)
            dp = dp2
        return max(0, dp[N-1][N-1])
```

```Java [ ]
class Solution {
    public int cherryPickup(int[][] grid) {
        int N = grid.length;
        int[][] dp = new int[N][N];
        for (int[] row: dp) Arrays.fill(row, Integer.MIN_VALUE);
        dp[0][0] = grid[0][0];

        for (int t = 1; t <= 2*N - 2; ++t) {
            int[][] dp2 = new int[N][N];
            for (int[] row: dp2) Arrays.fill(row, Integer.MIN_VALUE);

            for (int i = Math.max(0, t-(N-1)); i <= Math.min(N-1, t); ++i) {
                for (int j = Math.max(0, t-(N-1)); j <= Math.min(N-1, t); ++j) {
                    if (grid[i][t-i] == -1 || grid[j][t-j] == -1) continue;
                    int val = grid[i][t-i];
                    if (i != j) val += grid[j][t-j];
                    for (int pi = i-1; pi <= i; ++pi)
                        for (int pj = j-1; pj <= j; ++pj)
                            if (pi >= 0 && pj >= 0)
                                dp2[i][j] = Math.max(dp2[i][j], dp[pi][pj] + val);
                }
            }
            dp = dp2;
        }
        return Math.max(0, dp[N-1][N-1]);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^3)$。其中 $N$ 是 `grid` 的长度。
* 空间复杂度：$O(N^2)$，`dp` 和 `dp2` 所使用的空间