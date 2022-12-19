![image.png](https://pic.leetcode-cn.com/ffe6569da930db42c2d0c3983e8fa58a588d00528d2824b11b262d5533b7eb04-image.png)

### 解题思路
```js
  优先队列的动态规划：除了记忆化搜索还有动态规划之外，我还有另一种想法：不知可不可行：
  把矩阵的数字排序放到一个队列当中，从最小的开始分析，一直到矩阵中的所有数字分析完，
  分析的过程就是，看这个点的四周到自己的最长路径
  
  分析过程中，如果它四周的某个点还没有被分析过或者越界就跳过，分析过的话，就比较出四个方向
  路径最长的一条 + 1 更新为当前点的值
```

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number}
 */

var longestIncreasingPath = function(matrix) {
  if (matrix.length === 0 || matrix[0].length === 0) return 0;
  
  let rowLimit = matrix.length,
      colLimit = matrix[0].length,
      dp = new Array(rowLimit),
      analysed = new Array(rowLimit), // 是否分析过的标记二维数组
      queue = [],
      maxLong = 1;
  
  // 初始化 dp，都为 undefined 即可，因为都没分析过
  for (let i = 0; i < rowLimit; i++) {
    analysed[i] = new Array(colLimit);
    dp[i] = new Array(colLimit);
  }
  
  // 初始化队列
  for (let row = 0; row < rowLimit; row++) {
    for (let col = 0; col < colLimit; col++) {
      queue.push( [row, col] );
    }
  }
  
  // 对队列排序，正序，小的在前(这里正序、逆序都可以)，主要是按照矩阵中值的大小有顺序即可，为了后面从小到大拿出矩阵中的坐标进行分析
  queue.sort((a, b) => matrix[ a[0] ][ a[1] ] - matrix[ b[0] ][ b[1] ]);
  
  // 从小到大依次分析
  for (let i = 0; i < queue.length; i++) {
    let [row, col] = queue[i],
        currValue = matrix[row][col];
    
    let max = 0;
    
    let ways = [
      [-1, 0], [0, 1], [1, 0], [0, -1]
    ];
    
    for (let way of ways) {
      let next_row = row + way[0],
          next_col = col + way[1];
      
      if (
        next_row < 0 || next_col < 0 || next_row >= rowLimit ||
        next_col >= colLimit ||
        matrix[next_row][next_col] >= currValue ||
        !analysed[next_row][next_col]
      ) {
        continue;
      }
      
      max = Math.max(dp[next_row][next_col], max);
    }
    
    dp[row][col] = max + 1;
    analysed[row][col] = 1;
    maxLong = Math.max(dp[row][col], maxLong);
  }
  
  return maxLong;
}
```