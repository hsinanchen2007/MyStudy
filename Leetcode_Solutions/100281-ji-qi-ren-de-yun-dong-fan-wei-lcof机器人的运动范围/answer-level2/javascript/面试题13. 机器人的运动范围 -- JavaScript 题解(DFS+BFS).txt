# DFS 解法

```
var movingCount = function (m, n, k) {
    let visited = []
    for (let i = 0; i < m; i++) { visited[i] = [] }
    return dfs(0, 0, visited, m, n, k)
};

function dfs(x, y, visited, m, n, k) {
    // 边界 || 被访问过跳出
    if (x >= m || y >= n || visited[x][y] || getSum(x) + getSum(y) > k) return 0;
    // 已被访问过
    visited[x][y] = 1;
    // 运动范围只在第一象限
    return 1 + dfs(x + 1, y, visited, m, n, k) + dfs(x, y + 1, visited, m, n, k);
}
// 计算数位和
function getSum(num) {
    let sum = 0;
    while (num > 0) {
        sum += num % 10;
        num = parseInt(num / 10);
    }
    return sum;
}
```

# BFS解法
```
var movingCount = function (m, n, k) {
    let res = 1;
    let visited = [];
    for (let i = 0; i < m; i++) { visited[i] = [] }
    let dir = [[1, 0], [0, 1]];
    let que = [];
    que.push([0, 0])
    while (que.length > 0) {
        let temp = que.shift();
        for (let i = 0; i < dir.length; i++) {
            let x = temp[0] + dir[i][0];
            let y = temp[1] + dir[i][1];
            if (x < m && y < n && !visited[x][y] && getSum(x) + getSum(y) <= k) {
                que.push([x, y]);
                visited[x][y] = 1;
                res++;
            }
        }
    }
    return res;
};
function getSum(num) {
    let sum = 0;
    while (num > 0) {
        sum += num % 10;
        num = parseInt(num / 10);
    }
    return sum;
}
```

