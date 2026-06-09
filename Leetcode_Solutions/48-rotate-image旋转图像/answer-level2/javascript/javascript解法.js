### 解题思路
先反转再交换

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const { length } = matrix
    for (let i = 0; i < length; i++) {
        for (let j = 0; j < length / 2; j++) {
            let temp = matrix[i][j]
            matrix[i][j] = matrix[i][length - 1 - j]
            matrix[i][length - 1 - j] = temp
        }
    }

    for (let i = 0; i < length; i++) {
        for (let j = 0; j < length - i; j++) {
            let temp = matrix[i][j]
            matrix[i][j] = matrix[length - 1 - j][length - 1 - i]
            matrix[length - 1 - j][length - 1 - i] = temp
        }
    }

    return matrix
};
```