注意三点
- 标记该元素已使用
- 上下左右不能超边界
- 没找到最终值的时候恢复上一个节点的值
```javascript
var exist = function (board, word) {
  //越界处理
  board[-1] = []; // 这里处理比较比较巧妙，利用了js的特性
  board.push([])

  //寻找首个字母
  for (let y = 0; y < board.length; y++) {
    for (let x = 0; x < board[0].length; x++) {
      if (word[0] === board[y][x] && dfs(word,board,y, x, 0)) return true
    }
  }
  return false
};
const dfs = function(word,board,y, x, i){
    if (i + 1 === word.length) return true
    var tmp = board[y][x];
    // 标记该元素已使用
    board[y][x] = false
    if (board[y][x + 1] === word[i + 1] && dfs(word,board,y, x + 1, i + 1)) return true
    if (board[y][x - 1] === word[i + 1] && dfs(word,board,y, x - 1, i + 1)) return true
    if (board[y + 1][x] === word[i + 1] && dfs(word,board,y + 1, x, i + 1)) return true
    if (board[y - 1][x] === word[i + 1] && dfs(word,board,y - 1, x, i + 1)) return true
    // 回溯
    board[y][x] = tmp
  }
```