1. 先翻转整个矩阵
2. 再翻转每一行

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let len = matrix.length;
    if(!len) return [];
    for(let i = 0; i < len; i++) {
        for(let j = i; j < len; j++) {
            let temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for(let i = 0; i < len; i++) {
        for(let j = 0; j < len / 2; j++) {
            let temp = matrix[i][j];
            matrix[i][j] = matrix[i][len - j-1];
            matrix[i][len-j-1] = temp; 
        }
    }
}
```