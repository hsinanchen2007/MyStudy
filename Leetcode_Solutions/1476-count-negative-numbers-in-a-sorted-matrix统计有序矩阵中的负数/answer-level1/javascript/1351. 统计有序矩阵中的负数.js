### 解题思路
有序矩阵 -> 任何一个负数的右下方矩阵都是负数, 所以遍历到一个负数之后就可以缩小col的范围

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function (grid) {
    let row = 0, col = 0, height = grid.length, width = grid[0].length
    let result = 0
    while (row < height) {
        while (col < width) {
            if (grid[row][col] < 0) {
                result += (height - row) * (width - col)
                width = col
            }
            col++
        }
        row++
        col = 0
    }
    return result
};
```