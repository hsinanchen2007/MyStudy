### 解题思路
![image.png](https://pic.leetcode-cn.com/d7878c9cb21acd90b1802718e9c644d3e763e250b33185344526d4fa3ec70c70-image.png)

遍历二维数组，先累加面积 4*n+2 （4个立面，顶底2两个面），然后依次检查是否和右边贴住，贴住的话，面积减少两份“矮的那根”的高度，同理，再检查和下面是否贴住。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    if (grid === [[0]]) return 0;

    let len = grid.length,
        surfc = 0;
    for (let i = 0; i < len; i++) {
        for (let j = 0; j < len; j++) {
            surfc += grid[i][j] > 0 ? (4 * grid[i][j] + 2) : 0;
            surfc -= (j < len - 1 && grid[i][j + 1] > 0) ? 2 * Math.min(grid[i][j], grid[i][j + 1]) : 0;
            surfc -= (i < len - 1 && grid[i + 1][j] > 0) ? 2 * Math.min(grid[i][j], grid[i + 1][j]) : 0;
        }
    }
    return surfc;
};
```