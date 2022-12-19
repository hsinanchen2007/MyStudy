#### 方法一：计数

如果位于 `(x, y)` 的服务器能够与至少一台其它服务器进行通信，就必须满足：要么第 `x` 行有一台其它服务器，要么第 `y` 列有一台其它服务器。

因此我们先遍历所有的服务器，并用数组 `count_m` 和 `count_n` 分别记录每一行和每一列的服务器数量。在计数完成之后，我们再次遍历所有的服务器，如果位于 `(x, y)` 的服务器满足 `count_m[x] > 1`（即第 `x` 行至少有一台其它服务器）或 `count_n[y] > 1`（即第 `y` 列至少有一台其它服务器），那么它就能够与至少一台其它服务器进行通信，将其计入答案。

```C++ [sol1]
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> count_m(m), count_n(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++count_m[i];
                    ++count_n[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (count_m[i] > 1 || count_n[j] > 1)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

```Python [sol1]
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        count_m, count_n = [0] * m, [0] * n
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    count_m[i] += 1
                    count_n[j] += 1
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and (count_m[i] > 1 or count_n[j] > 1):
                    ans += 1
        return ans
```

**复杂度分析**

- 时间复杂度：$O(MN)$，其中 $M$ 和 $N$ 分别是网格的高和宽。

- 空间复杂度：$O(M + N)$。