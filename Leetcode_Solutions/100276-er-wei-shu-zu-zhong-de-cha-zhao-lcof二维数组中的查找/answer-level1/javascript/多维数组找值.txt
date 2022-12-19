### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
  if(matrix == null || matrix.length === 0 || matrix[0].length === 0) {
      return false;
  }
  let row = 0;
  let column = matrix[0].length-1;
  while(row<matrix.length && column >= 0) {
    if(target === matrix[row][column]) {
        return true;
    } else if(matrix[row][column] > target) {
        column--;
    } else if(matrix[row][column]<target){
        row++;
    }
  }
  return false;
};
```