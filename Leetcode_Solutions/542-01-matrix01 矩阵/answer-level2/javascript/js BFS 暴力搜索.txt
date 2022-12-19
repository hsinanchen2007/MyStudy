![image.png](https://pic.leetcode-cn.com/731d4b9ca7f46c9938f1a89e030aed7f15737e067e871df7e5714c56d5f5b190-image.png)

### 解题思路
```javascript
/*
  对每一个节点进行广度优先搜索
*/
```

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */

var updateMatrix = function(matrix) {
  let ans = JSON.parse( JSON.stringify( matrix ) ),
      queue = [];
  
  for (let row = 0; row < matrix.length; row++) {
    for (let col = 0; col < matrix[0].length; col++) {
      if (matrix[row][col] === 0) continue;
      queue.push( [row, col, 0] );
      ans[row][col] = bfs();
      queue = [];
    }
  };
  
  // 广度优先搜索
  function bfs() {
    let step = 0;
    while (queue.length > 0) {
      let curr = queue.shift();
      step = curr[2];
      
      // 四个方向
      let ways = [ [-1, 0], [0, 1], [1, 0], [0, -1] ];
      for (let i = 0; i < 4; i++) {
        let r = curr[0] + ways[i][0],
            c = curr[1] + ways[i][1];
        // 如果越界就跳过
        if (r < 0 || r >= matrix.length || c < 0 || c >= matrix[0].length) {
          continue;
        }
        
        // 如果是 0，那么 step + 1; 返回
        if (matrix[r][c] === 0) {
          step += 1;
          queue = [];
          break;
        }
        
        // 记录到 queue 中，step + 1;
        queue.push( [r, c, step + 1] );
      }
    }
    
    return step;
  }
  
  return ans;
};
```