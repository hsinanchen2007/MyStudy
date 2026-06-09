### 解题思路
![image.png](https://pic.leetcode-cn.com/dc0a7f892ed9742cfe572ef77af81eeabb9a9cfacd59f88a07aac1a917533576-image.png)

这个题解的意义是我终于真正的理解了动态规划。纪念一下，嘿嘿！

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxValue = function(grid) {
    //dp[i][j] = max{dp[i - 1][j], dp[i][j - 1]} + data[i][j]
    const xLen = grid.length;
    if(!xLen) return 0;
    const yLen = grid[0].length;
    let dp = [];
    for(let i = 0; i < xLen + 2; i ++) {//最外层都是0，就不用考虑边界问题了，下面的状态转移方程也就优一点变化，但中心思想不变。
        let arr = new Array(yLen + 2).fill(0);
        dp[i] = arr;
    }
    // console.log(dp)
    for(let x = 0; x < xLen; x ++) {
        for(let y = 0; y < yLen; y ++) {
            dp[x + 1][y + 1] = Math.max(dp[x][y + 1], dp[x + 1][y]) + grid[x][y];
        }
    }
    // console.log(dp)
    return dp[xLen][yLen];
};
```