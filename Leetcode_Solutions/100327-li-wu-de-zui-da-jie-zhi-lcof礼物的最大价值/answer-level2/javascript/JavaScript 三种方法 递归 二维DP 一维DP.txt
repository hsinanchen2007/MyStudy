### 解题思路

由于只能向下走或向右走，假设 f(i, j) 表示从 [i, j] 位置开始能搜集到的最大礼物，那么: 

f(i, j) = grid[i][j] + Math.max(f(i+1, j), f(i, j+1))

这么看显然是可以用递归来实现的。当然这也就是我们的 DP 的状态转移方程了。

方法一：递归（面试中也可先写出来）
方法二：递归 + 缓存
方法三：二维 DP (推荐，面试中可以使用，并给出方法四的优化)
方法四：一维 DP

### 方法一：递归，超时

```javascript
var maxValue = function(grid) {
    let rows = grid.length
    if (!rows) return 0
    let cols = grid[0].length
    return recurse(0, 0)

    function recurse(i, j) {
        if (i >= rows || j >= cols) return 0

        return grid[i][j] + Math.max(recurse(i, j+1), recurse(i+1, j))
    }
};
```

### 方法二：递归 + 缓存，通过

```javascript
var maxValue = function(grid) {
    let rows = grid.length
    if (!rows) return 0
    let cols = grid[0].length
    let max = 0
    let map = new Map()
    return recurse(0, 0)

    function recurse(i, j) {
        if (i >= rows || j >= cols) return 0
        if (map.has(i*cols+j)) return map.get(i*cols+j)

        let a = recurse(i+1, j)
        let b = recurse(i, j+1)
        let max = grid[i][j] + Math.max(a, b)
        map.set(i*cols+j, max)

        return max
    }
};
```

### 方法三：二维 DP，通过（推荐）

```javascript
var maxValue = function(grid) {
    let rows = grid.length
    if (!rows) return 0
    let cols = grid[0].length
    let dp = Array(rows).fill(0).map(i => Array(cols).fill(0))

    for(let i = rows-1; i>=0; i--) {
        for(let j = cols-1; j>=0; j--) {
            let a = i+1 >= rows ? 0 : dp[i+1][j]
            let b = j+1 >= cols ? 0 : dp[i][j+1]

            dp[i][j] = grid[i][j] + Math.max(a, b)
        }
    }

    return dp[0][0]
};
```

### 方法四：一维 DP，通过 (推荐)

```javascript
var maxValue = function(grid) {
    let rows = grid.length
    if (!rows) return 0
    let cols = grid[0].length
    let dp = Array(cols).fill(0)
    for(let i = rows-1; i>=0; i--) {
        for(let j = cols-1; j>=0; j--) {
            let a = i+1 >= rows ? 0 : dp[j]
            let b = j+1 >= cols ? 0 : dp[j+1]

            dp[j] = grid[i][j] + Math.max(a, b)
        }
    }
    return dp[0]
};
```
