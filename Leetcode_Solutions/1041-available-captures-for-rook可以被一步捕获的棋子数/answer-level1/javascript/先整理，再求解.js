### 解题思路
这道题首先要理解题意
1. 如果没有阻挡，车可以无限移动，除非自己停止
2. 遇到象，停止。停止的意思是不能向前，但可以向后
3. 遇到边，停止。停止的意思是不能向前，但可以向后
4. 遇到卒，吃掉，然后在这个方向上必须停止。

解题方法，先整理
1. 去掉没用的信息
2. 把二维问题转为一维问题。

这样代码更清晰。速度也不慢，60 ms 打几败 85

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function (board) {
  let count = 0

  let info = []
  for (let i = 0; i < 8; i++) {
    let item = []
    for (let j = 0; j < 8; j++) {
      if ('.' !== board[i][j]) {
        item.push(board[i][j])
      }
    }
    item.length > 0 && info.push(item)
  }
  for (let j = 0; j < 8; j++) {
    let item = []
    for (let i = 0; i < 8; i++) {
      if ('.' !== board[i][j]) {
        item.push(board[i][j])
      }
    }
    item.length > 0 && info.push(item)
  }
  //整理好后的info是个一维数组
  for (let item of info) {
    let index = item.indexOf('R')
    if (index < 0) continue
    let i = index
    while (i--) {
      if (item[i] === 'B') break;
      if (item[i] === 'p') {
        count++
        break
      }
    }
    i = index + 1
    while (i < item.length) {
      if (item[i] === 'B') break;
      if (item[i] === 'p') {
        count++
        break
      }
      i++
    }
  }
  return count
};
```