### 解题思路

## 判空条件
- 矩阵为 `null`
- 矩阵行数为0
- 矩阵每一行的元素个数为0

## 提前缓存
1. 构造一个比原矩阵大一圈的矩阵`dp`，矩阵的所有初始值都为0
2. 计算原矩阵中，以(0,0)为左上角，以任意每一个点作为***右下角***的矩阵的和，并存入` dp[i + 1][j + 1]`
`dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] + matrix[i][j] - dp[i][j];`

## 动态规划求解
`dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];`
通过上述公式求需要的两点矩阵的和

## JavaScript代码注意事项
1. dp矩阵作为`NumMatrix`原型的一个属性存在，可以被所有原型方法调用，所以应该存在`this`中
2. JavaScript的初始矩阵如果没写明元素直接使用，会报错，所以需要所有位置都有初始值


### 代码

```javascript
/**
 * @description 给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。
 * @param {number[][]} matrix
 */
var NumMatrix = function (matrix) {
    if (matrix == null || matrix.length === 0 || matrix[0].length === 0) return;
    const h = matrix.length,
        w = matrix[0].length;

    const dp = [];
    for (let i = 0; i <= h; i++) {
        const r = [];
        for (let j = 0; j <= w; j++) r.push(null);
        dp.push(r);
    }

    for (let i = 0; i < h; i++) {
        for (let j = 0; j < w; j++) {
            dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] + matrix[i][j] - dp[i][j];
        }
    }

    this.dp = dp;
}

/** 
 * @param {number} row1 
 * @param {number} col1 
 * @param {number} row2 
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function (row1, col1, row2, col2) {
    return this.dp[row2 + 1][col2 + 1] -
        this.dp[row1][col2 + 1] -
        this.dp[row2 + 1][col1] +
        this.dp[row1][col1];
};

/** 
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
```