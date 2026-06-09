思路是先沿对角线进行一次翻转，使用temp存储变量达到原地翻转，此时每列数字都在旋转90度后所在的行了，但是顺序是相反的，此时再对每行进行一次翻转即可
```
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let m = matrix.length, n = matrix[0].length
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < i; j++) {
            let temp = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = temp
        }
    }
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n/2; j++) {
            let temp = matrix[i][j]
            matrix[i][j] = matrix[i][n-j-1]
            matrix[i][n-j-1] = temp 
        }
    }
    return matrix
};
```
