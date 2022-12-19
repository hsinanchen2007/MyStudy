### 解题思路
对每一个格子，各个方向进行遍历，然后判断是否需要发生状态变化。最后需要复制一份数组，来确保每次遍历的都是原数组

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
  let row = board.length
  let col = board[0].length
  function getNeighbors(arr,x,y) {
     let count = 0
     if(x > 0) {
          count += arr[x-1][y]
          if(y > 0) {
            count += arr[x-1][y-1]
          }
          if(y < col-1) {
            count += arr[x-1][y+1]
          }
        }
     if(x<row-1) {
         count+=arr[x+1][y]
         if(y>0) {
             count+=arr[x+1][y-1]
         }
         if(y<col-1) {
             count+=arr[x+1][y+1]
         }
     }
     if(y>0) {
         count+=arr[x][y-1]
     }
     if(y<col-1) {
         count+=arr[x][y+1]
     }
     if(arr[x][y] === 1) {
        if(count<2||count>3) return true
     }
     if(arr[x][y] === 0 && count===3) return true
     return false
  }
  let copy = [...board.map(i=>i.slice())]
  for(let i = 0;i<row;i++) {
      for(let j = 0;j<col;j++) {
          if(getNeighbors(copy,i,j)) {
              board[i][j]=!board[i][j]
          }
      }
  }
};



```