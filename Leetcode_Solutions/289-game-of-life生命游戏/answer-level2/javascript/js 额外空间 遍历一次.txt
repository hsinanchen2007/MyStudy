![image.png](https://pic.leetcode-cn.com/9e314b224038e545616633d30e184d81135131602ea63576f94db612096810ee-image.png)

### 解题思路
```js
  如果不使用额外空间的话，就在给细胞加两个状态，一个是死的变成活的，一个是活的变成死的，
  这样在原数组操作的时候只需要还原一下状态就可以了

  使用了额外空间
  对 copy 出来的 newBoard 遍历一次，每次统计它周围的八个细胞状态，
  更新 board 中细胞的状态
```

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */

var gameOfLife = function(board) {
  if (board.length === 0 || board[0].length === 0) return null;
  let rowLimit = board.length,
      colLimit = board[0].length,
      newBoard = JSON.parse( JSON.stringify( board ) );
  
  for (let i = 0; i < rowLimit; i++) {
    for (let j = 0; j < colLimit; j++) {
      let c = newBoard[i][j];
      let ways = [
        [-1, -1], [-1, 0], [-1, 1], [0, 1],
        [1, 1], [1, 0], [1, -1], [0, -1]
      ], count = 0;
      
      for (let way of ways) {
        let next_row = i + way[0],
            next_col = j + way[1];
        if (next_row < 0 || next_row >= rowLimit || next_col < 0 ||
           next_col >= colLimit) {
          continue;
        }
        if (newBoard[next_row][next_col] == 1) count++;
      }
      
      if (c == 1 && (count < 2 || count > 3)) {
        board[i][j] = '0';
      } else {
        if (c == 0 && count === 3) {
          board[i][j] = '1';
        }
      }
    }
  }
};
```