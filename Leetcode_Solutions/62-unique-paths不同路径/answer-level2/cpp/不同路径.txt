定义变量 `path[i][j]`：终点是`[i][j]`时，有`path[i][j]`种走法到该终点。

因为规定每次只能向右或向下走，所以导致两种现象：
- `path[i][j] = path[i-1][j] + path[i][j-1]`
- `i = 0` 那一列和 `j = 0` 那一行都属于边界，`i = 0`该列上的点只能通过一直向下到达；`j = 0`该行上的点只能通过一直向右到达。所以 `path[0][j] = 0, path[i][0] = 0`

```
class Solution {
public:
    int uniquePaths(int m, int n) {
        int path[m][n];
        int i, j;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    path[i][j] = 1;
                else
                    path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }

        return path[i - 1][j - 1];
    }
};
```


