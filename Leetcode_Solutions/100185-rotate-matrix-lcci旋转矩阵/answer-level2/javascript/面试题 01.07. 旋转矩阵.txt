### 解题思路
思路2, 注意奇偶边界parseInt

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
    let n = matrix.length
    for (let r = 0; r < parseInt(n / 2); r++) {
        for (let c = 0; c < parseInt((n + 1) / 2); c++) {
            let tmp = matrix[r][c]
            matrix[r][c] = matrix[n - c - 1][r]
            matrix[n - c - 1][r] = matrix[n - r - 1][n - c - 1]
            matrix[n - r - 1][n - c - 1] = matrix[c][n - r - 1]
            matrix[c][n - r - 1] = tmp
        }
    }
};
```