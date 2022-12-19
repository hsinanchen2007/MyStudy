
### 代码

#### 位数之和
* 数位之和：x % 10 取个位数，再x/10将数按10进制右移一位，个位移除，10位移到个位，再取个位数，直到x为0，累加所有个位数即可

```javascript
function sum(x) {
    let s = 0
    while (x) {
        s += x % 10
        x = parseInt(x / 10)
    }
    return s
}
```

> 向左、向右、向上、向下简化为向右和向下，机器人从左上角到下一个格子，必须由下一个格子的左或上方进入，所以这两个方向可以简化掉。以下三种解法均用了此优化思路

#### DFS
* 注意要判断是否重复计算节点，可以缓存访问过的节点进行判重

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
    const visited = new Set()
    return dfs(0, 0, m, n, k, visited)
};
function dfs(i, j, m, n, k, visited) {
    if (visited.has(`${i}-${j}`) || i >= m || j >= n || sum(i) + sum(j) > k) return 0
    visited.add(`${i}-${j}`)
    return 1 + dfs(i + 1, j, m, n, k, visited) + dfs(i, j + 1, m, n, k, visited)
}
```

#### BFS
```javascript
var movingCount = function (m, n, k) {
    const visited = new Set()
    const queue = [[0, 0]]
    const directions = [[1, 0], [0, 1]]
    let res = 0
    while (queue.length) {
        let [oi, oj] = queue.shift()
        res++
        for (const d of directions) {
            let i = d[0] + oi
            let j = d[1] + oj
            if (visited.has(`${i}-${j}`) || i >= m || j >= n || sum(i) + sum(j) > k) continue
            visited.add(`${i}-${j}`)
            queue.push([i, j])
        }
    }
    return res
}
```


#### 动态递推
* 状态定义：dp[i][j] 机器人可达i,j位置的格子，值为1，否则值为0
* dp方程：dp[i][j] = dp[i-1][j] || dp[i][j-1], sum(i) + sum(j) <= k
* i,j是否可达，取决于左边和上边的格子是否可达，且满足位数之和小于k
* base case: dp[0][0] = 1

```javascript
var movingCount = function (m, n, k) {
    const dp = new Array(m).fill().map(i => new Array(n).fill(0))
    dp[0][0] = 1
    let res = 1
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if ((i === 0 && j == 0) || sum(i) + sum(j) > k) continue
            // 左边格子是否可达
            if (i - 1 >= 0) dp[i][j] |= dp[i - 1][j]
            // 上边格子是否可达
            if (j - 1 >= 0) dp[i][j] |= dp[i][j - 1]
            res += dp[i][j]
        }
    }
    return res
}

```