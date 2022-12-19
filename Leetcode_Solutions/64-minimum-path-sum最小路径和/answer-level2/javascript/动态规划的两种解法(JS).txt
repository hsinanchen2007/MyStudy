### 由上至下的动态规划

* 假如我们有在某一步`A[i][j]`, 其最小步数值为`A[i + 1][j]`以及`A[i][j+1]`的最小值加上当前位置的步数`A[i][j]`。
* 需存储计算过的步数，避免重复运算超出时间限制。
* 时间复杂度刚好为`O(m*n)`，改为由下至上的动态规划可以避免多使用一个数组。

```javascript []
var minPathSum = function (grid) {
    const m = grid.length,
        n = grid[0].length;
    const memo = [...Array(m)].map(() => [...Array(n)]);
    const calcPath = function (i, j) {
        if (i + 1 === m && j + 1 === n) {
            return grid[i][j];
        }
        if (memo[i][j]) {
            return memo[i][j];
        }
        // 计算往右走以及往下走的步数，取最小值
        let min = Infinity;
        if (i + 1 < m) {
            min = Math.min(min, calcPath(i + 1, j));
        }
        if (j + 1 < n) {
            min = Math.min(min, calcPath(i, j + 1));
        }
        memo[i][j] = min + grid[i][j];
        return memo[i][j];
    }
    return calcPath(0, 0);
};
```

### 由下至上的动态规划

* 计算从右下角开始遍历，计算每一个点到达`A[m - 1][n - 1]`的最小步数。
* 对于底部一行，其步数为自身的步数加右侧的总步数，即`A[i][j] += A[i][j + 1]`。
* 对于右侧一列，其步数为自身的步数加下侧的总步数，即`A[i][j] += A[i + 1][j]`。
* 对于剩余的数，其步数为自身的步数加右侧、下侧最小值，即`A[i][j] += Math.min(A[i + 1][j], A[i][j + 1])`。

```javascript []
var minPathSum = function (grid) {
    const m = grid.length,
        n = grid[0].length;
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            if (i + 1 < m && j + 1 < n) {
                grid[i][j] += Math.min(grid[i + 1][j], grid[i][j + 1]);
            } else if (i + 1 < m) {
                grid[i][j] += grid[i + 1][j];
            } else if (j + 1 < n) {
                grid[i][j] += grid[i][j + 1];
            }
        }
    }
    return grid[0][0];
};
```