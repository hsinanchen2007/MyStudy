判断每个元素 arr[i][j] 【i>=1&&j>=1】是否和这个元素左上角的元素 arr[i-1][j-1] 相等

```js
var isToeplitzMatrix = function(matrix) {
    let row = matrix.length; 
    let col = matrix[0].length;
    for (let i = 1; i < row; i++) {
        for (let j = 1; j < col; j++) {
            if (matrix[i][j] != matrix[i-1][j-1]) {
                return false
            }
        }
    }
    return true
};

```