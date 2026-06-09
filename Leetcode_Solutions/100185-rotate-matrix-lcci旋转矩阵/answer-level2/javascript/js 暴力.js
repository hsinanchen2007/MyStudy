![image.png](https://pic.leetcode-cn.com/9605d681b28c0dd28f63a1375312302feb2fe8b4d6ea0894bdffbb4946456457-image.png)
```js
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const copy = JSON.parse(JSON.stringify(matrix));
    const col = matrix[0].length - 1;
    for(let i = 0; i <= col; i++) {
        for(let j = 0; j < matrix.length; j++) {
            matrix[i][j] = copy[col - j][i];
        }
    }
    return matrix;
};
```