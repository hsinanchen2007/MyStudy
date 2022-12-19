![image.png](https://pic.leetcode-cn.com/b283219733bd5043797c2785a3f9eeb925b6c810920ba25758d3094d5b590e0c-image.png)

### 解题思路
```js
  思路：
  把每一行的最小值，和每一列的最大值存到一个 map 中，记录 2 次的就是幸运数
```

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */

var luckyNumbers  = function(matrix) {
  if (matrix.length === 0 || matrix[0].length === 0) return [];
  
  let row = matrix.length, col = matrix[0].length, map = {}, ans = [];
  
  for (let i = 0; i < row; i++) {
    let rowMin = null;
    for (let j = 0; j < col; j++) {
      if (rowMin === null || matrix[i][j] < rowMin) {
        rowMin = matrix[i][j];
      }
    }
    
    if (map[ rowMin ] === undefined) {
      map[ rowMin ] = 1;
    } else {
      map[ rowMin ] ++;
      ans.push( rowMin );
    }
  }
  
  for (let i = 0; i < col; i++) {
    let colMin = null;
    for (let j = 0; j < row; j++) {
      if (colMin === null || matrix[j][i] > colMin) {
        colMin = matrix[j][i];
      }
    }
    
    if (map[ colMin ] === undefined) {
      map[ colMin ] = 1;
    } else {
      map[ colMin ] ++;
      ans.push( colMin );
    }
  }
  
  return ans;
};
```