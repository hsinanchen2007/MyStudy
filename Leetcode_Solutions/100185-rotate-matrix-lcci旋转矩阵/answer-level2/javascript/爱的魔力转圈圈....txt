### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * 
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {

    // 解(口决)：爱的魔力转圈圈... 转了一圈再一圈...

    const N = matrix.length
    for (let i = 0; i < N; i++) {
        for (let j = i + 1; j < N; j++) {
            // xor 异或位运算 === swap
            matrix[i][j] = matrix[i][j] ^ matrix[j][i]
            matrix[j][i] = matrix[i][j] ^ matrix[j][i]
            matrix[i][j] = matrix[i][j] ^ matrix[j][i]
        }
    }

    for (let i = 0; i < N; i++)
        matrix[i].reverse()
};

```