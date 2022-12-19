### 解题思路
参考题解的动态规划解法
![Snipaste_2020-03-29_14-33-38.png](https://pic.leetcode-cn.com/aba59027a4afbb85c2261291564d19025ba1f44a75bdafb6b737835f751c4064-Snipaste_2020-03-29_14-33-38.png)


### 代码

```javascript
var maxDistance = function (grid) {
    if (grid.length < 2) return -1
    let n = grid.length;
    // 创建 dp 状态矩阵
    let dp = new Array(n);
    for (let i = 0; i < n; i++) {
        dp[i] = new Array(n);
    }

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            dp[i][j] = (grid[i][j] ? 0 : Infinity);
        }
    }
    // 从左上向右下遍历
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j]) continue
            if (i - 1 >= 0) dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + 1);
            if (j - 1 >= 0) dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    // 从右下向左上遍历
    for (let i = n - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            if (grid[i][j]) continue
            if (i + 1 < n) dp[i][j] = Math.min(dp[i][j], dp[i + 1][j] + 1);
            if (j + 1 < n) dp[i][j] = Math.min(dp[i][j], dp[i][j + 1] + 1);
        }
    }
    let ans = -1;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (!grid[i][j]) ans = Math.max(ans, dp[i][j]);
        }
    }
    if (ans === Infinity) {
        return -1
    } else {
        return ans
    }
};
```
![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/dd3593cb31c56647e71aa4269595e23b9492ae18ac1ad0bc566d28e8bd764c90-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)