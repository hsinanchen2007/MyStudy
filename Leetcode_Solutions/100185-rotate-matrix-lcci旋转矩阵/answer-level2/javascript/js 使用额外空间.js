![image.png](https://pic.leetcode-cn.com/2413b4c2e15095489322220643e78781f934af0deddcb82d09d4b9e170a98dba-image.png)

### 解题思路
```js
  使用额外的二维矩阵
```

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */

var rotate = function(matrix) {
  if (matrix.length === 0 || matrix[0].length === 0) return [];
  
  let copy = JSON.parse( JSON.stringify( matrix ) ),
      rowLimit = matrix.length,
      colLimit = matrix[0].length;
  
  for (let col = 0; col < colLimit; col++) {
    for (let row = rowLimit - 1; row >= 0; row--){
      matrix[col][rowLimit - 1 - row] = copy[row][col];
    }
  }
};
```