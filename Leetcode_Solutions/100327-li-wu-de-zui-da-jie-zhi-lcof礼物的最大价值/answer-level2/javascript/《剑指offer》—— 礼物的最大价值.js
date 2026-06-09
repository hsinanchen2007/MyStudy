[点击查看原题](https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/)
[点击查看原文](https://juejin.im/post/5e4bafd551882549274a4d42)

## 题目描述

在一个 $m*n$ 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 $0$）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

## 解题思路

因为每次只能「向右」或者「向左」移动，那么移动到第 $m$ 行 $n$ 列的格子能获得的价值为「左边」或者「上边」格子的价值与自身格子价值的和，所以可以推导出：  
$grid[m][n] = max(grid[m - 1][n], grid[m][n - 1]) + grid[m][n]$


## 示例代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxValue = function(grid) {
    let xLen = grid.length
    let yLen = grid[0].length
    for (let i = 0; i < xLen; i++) {
        for (let j = 0; j < yLen; j++) {
            if (i - 1 >= 0 && j - 1 >= 0) {
                grid[i][j] += Math.max(grid[i - 1][j], grid[i][j - 1])
            } else if (i - 1 >= 0) {
                grid[i][j] += grid[i - 1][j]
            } else if (j - 1 >= 0) {
                grid[i][j] += grid[i][j - 1]
            }
        }
    }
    return grid[xLen - 1][yLen - 1]
};
```