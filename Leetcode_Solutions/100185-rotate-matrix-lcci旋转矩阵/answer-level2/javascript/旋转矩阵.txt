### 解题思路
旋转后第一行等于第一列 第n行等于第n列

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
   let dd = []
  dd = matrix.map((val, matrixIndex) => {
    let arr = []
    for (let i = val.length - 1; i >= 0; i--){
      // 第一行等于第一列，以此类推
      arr.push(matrix[i][matrixIndex])
    }
    return arr
  })
  matrix.forEach((val, index) => {
    matrix[index] = dd[index]
  })
};
```