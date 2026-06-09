### 解题思路

#### 1. 数组扁平化再查找

#### 2. 利用矩形的特性

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */

// 第一种解法
var findNumberIn2DArray = function(matrix, target) {
  const arr = [].concat(...matrix);
  if (arr.indexOf(target) == -1) {
    return false;
  } else {
    return true;
  }
};

// 第二种解法
var findNumberIn2DArray = function(matrix, target) {
  let found = false;
  if (matrix.length == 0 || matrix[0].length == 0) return false;
  const rows = matrix.length;
  const cols = matrix[0].length;
  if ( rows > 0 && cols > 0) {
    let row = 0;
    let col = cols - 1;
    while(row < rows && col >= 0) {
      if(matrix[row][col] == target){
        found = true;
        break;
      } else if (matrix[row][col]  > target) {
        --col;
      } else {
        ++row;
      }
    }
  }
  return found;
};
```