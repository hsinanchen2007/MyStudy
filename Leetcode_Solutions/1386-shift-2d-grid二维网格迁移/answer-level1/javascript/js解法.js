![image.png](https://pic.leetcode-cn.com/d6ba5c7d0d44c56f35d517a03285f046793191b03f971f511ebf32b2be3fa76a-image.png)

### 解题思路
将二位数组转换为一维数组，之后操作一位数组转移k个位置，再转换为二维数组

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */

var shiftGrid = function(grid, k) {
  let len = grid.length;
  if (len === 0) return [];
  
  let rLen = grid[0].length;
  if (rLen === 0) return [];
  
  let totalLen = len * rLen, single = [];
  for (let i = 0; i < len; i++) {
    let row = grid[i];
    for (let j = 0; j < rLen; j++) {
      single.push( row[j] );
    }
  }
  
  k = k % totalLen;
  
  let pre = single.slice( totalLen - k ), suf = single.slice(0, totalLen - k);
  single = pre.concat( suf );
  
  let i = 0, j = 0;
  for (let k = 0, length = totalLen; k < length; k++) {
    if (j === rLen) {
      i += 1;
      j = 0;
    }
    grid[i][j] = single[k];
    j++;
  }
  
  return grid;
};
```