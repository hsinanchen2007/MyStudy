
## 解法：动态规划

声明状态数组`dp`是一个 m\*n 的二维数组。`dp[i][j]`的默认值是 0，它的含义是：在坐标点（i，j）处，能得到的最大价值礼物。所以，整个棋盘的最大价值礼物就是 `dp[m-1][n-1]` 的值。

现在来看状态转移的过程：

-   出发点是左上角，且只能向右/下移动，所以第一列和第一行中的 dp 值，就等于：当前礼物价值+上一个 dp 值
-   对于一般坐标（i，j），`dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1])`

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
// 原文地址：https://xxoo521.com/2020-03-11-max-value-of-gift/
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxValue = function(grid) {
    const rowNum = grid.length;
    const colNum = grid[0].length;
    const dp = [];
    for (let i = 0; i < rowNum; ++i) {
        dp[i] = [];
        for (let j = 0; j < colNum; ++j) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = grid[0][0];
    for (let i = 1; i < rowNum; ++i) {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    }

    for (let j = 1; j < colNum; ++j) {
        dp[0][j] = grid[0][j] + dp[0][j - 1];
    }

    for (let i = 1; i < rowNum; ++i) {
        for (let j = 1; j < colNum; ++j) {
            dp[i][j] = grid[i][j] + Math.max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[rowNum - 1][colNum - 1];
};
```

时间复杂度和空间复杂度都是$O(N^2)$。在 leetcode 上显示，内存击败 100%，时间击败 96.63%：

![](https://pic.leetcode-cn.com/b22b3c3a8a2004a557cde0e58e1df4342268b6333ac570cce4fb7c013fcfc1db.jpg)

## 更多资料

**整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
