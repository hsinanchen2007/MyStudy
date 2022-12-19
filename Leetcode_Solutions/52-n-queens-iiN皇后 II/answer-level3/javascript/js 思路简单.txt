![image.png](https://pic.leetcode-cn.com/aa0ec8d989c8a3f9e2ef245817fde12c8d5523f6118637dfae5ce3068ce43f9f-image.png)

### 解题思路
回溯：
注意：已放置皇后的格子的行、列、对角线都不可放置
一个点左右对角线坐标的性质
- 左对角线：col - row = 一个常量
- 右对角线：col + row = 一个常量

思路：逐行遍历，遍历当前行的每一列
- 如果合法，在当前点放置皇后，继续遍历下一行
- 如果不合法，直接跳过就可以

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */

var totalNQueens = function(n) {
  let ans = 0,
      columns = [],
      leftSkew = [], // x - y = const
      rightSkew = []; // x + y = const
  
  // 判断当前位置是否可以放置皇后
  function canSet(row, col) {
    return !columns[col] && !leftSkew[col - row] && !rightSkew[col + row];
  }
  
  // 向当前位置放置一个皇后
  function addQueen(row, col) {
    columns[col] = true;
    leftSkew[col - row] = true;
    rightSkew[col + row] = true;
  }
  
  // 移除当前位置的皇后
  function removeQueen(row, col) {
    columns[col] = false;
    leftSkew[col - row] = false;
    rightSkew[col + row] = false;
  }
  
  function backtrack(row, queens) {
    // 判断是否找到一个解
    if (queens === n) {
      ans++;
      return ;
    }
    
    // 对当前行逐列遍历
    for (let col = 0; col < n; col++) {
      if (canSet(row, col)) {
        addQueen(row, col);
        backtrack(row + 1, queens + 1);
        removeQueen(row, col);
      }
    }
  };
  backtrack(0, 0);
  
  return ans;
};
```