区间和为 0 或者等于区域网格数量则是叶子节点
```javascript
/**
 * // Definition for a QuadTree node.
 * function Node(val,isLeaf,topLeft,topRight,bottomLeft,bottomRight) {
 *    this.val = val;
 *    this.isLeaf = isLeaf;
 *    this.topLeft = topLeft;
 *    this.topRight = topRight;
 *    this.bottomLeft = bottomLeft;
 *    this.bottomRight = bottomRight;
 * };
 */
/**
 * @param {number[][]} grid
 * @return {Node}
 */
var construct = function(grid) {
  if (grid.length === 0) {
    return null;
  }
  let n = grid.length;
  let m = grid[0].length;

  let dp = [];

  for (let i=0; i<=n; i++) {
    dp[i] = [];
    for (let j=0; j<=m; j++) {
      if (i === 0 || j === 0) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i - 1][j - 1];
      }
    }
  }

  return helper(0, 0, n - 1, m - 1);

  function helper(row1, col1, row2, col2) {
    let sum = sumRegion(row1, col1, row2, col2);
    let n = row2 - row1 + 1;
    if (sum === 0 || sum === n * n) {
      return new Node(sum === 0 ? false : true, true, null, null, null, null);
    }

    let topLeft = helper(row1, col1, row1 + n / 2 - 1, col1 + n / 2 - 1);
    let topRight = helper(row1, col1 + n / 2, row1 + n / 2 - 1, col2);
    let bottomLeft = helper(row1 + n / 2, col1, row2, col1 + n / 2 - 1);
    let bottomRight = helper(row1 + n / 2, col1 + n / 2, row2, col2);

    return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
  }

  function sumRegion(row1, col1, row2, col2) {
    return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
  }
};
```
