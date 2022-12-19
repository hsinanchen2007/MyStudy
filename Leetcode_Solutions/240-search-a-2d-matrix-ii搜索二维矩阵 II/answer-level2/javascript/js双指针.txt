```
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
  if(matrix.length === 0) return false
  let row = matrix.length , col = matrix[0].length,  i = row - 1, j = 0
  while( i >= 0 && j < col ) {
      if(matrix[i][j] > target) {
          i--
      } else if(matrix[i][j] < target) {
          j++
      } else {
          return true
      }
  }
  return false
};
```
