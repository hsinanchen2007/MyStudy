### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function(matrix) {
  let flag = true
  for(let i = 0; i < matrix.length; i++){
    let item = matrix[i]
    let next = matrix[i + 1]
    if (item && next) {
      item.forEach((t, j) => {
        if(next[j + 1] !== undefined && t !== next[j + 1]){
          flag = false
        }
      })
    }
  }
  return flag
};
```