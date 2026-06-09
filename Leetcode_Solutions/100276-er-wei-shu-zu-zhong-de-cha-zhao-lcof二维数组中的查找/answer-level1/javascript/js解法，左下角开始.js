### 解题思路
左下角，大的话向右移，小的话向左移

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function (array, target) {
  if (array.length === 0) return false
  const row = array[0].length
  const col = array.length

  let i = 0, j = col - 1;
  while (i <= row - 1 && j >= 0) {
    if (target > array[j][i]) {
      i++
    } else if (target < array[j][i]) {
      j--
    } else {
      return true
    }
  }

  return false
};
```