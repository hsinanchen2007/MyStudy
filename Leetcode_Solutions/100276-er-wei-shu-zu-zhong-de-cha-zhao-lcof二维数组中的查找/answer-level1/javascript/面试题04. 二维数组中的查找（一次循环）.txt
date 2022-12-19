### 解题思路
  从矩阵左下方第一个元素判断，如果此行第一个元素大于目标元素（这一行后面的肯定都大于目标元素），进入下次循环，循环内部用includes查找是否含有目标元素，找到后，手动结束外层循环（无需执行多余的循环内容了）

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
  let flag = false
  for (let i = matrix.length; i > 0; i--) {
    if (matrix[i-1][0] <= target) {
      if (matrix[i-1].includes(target)) {
        flag = true
        i = -1
      }
    }
  }
  return flag
};
```