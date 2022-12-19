### 解题思路

大家好，我是 17

思路就是穷举所有可能，对每一个点，都分上下左右四个方向搜索

要注意的是，题目说同一个单词只能用一次，其实这是简化了算法。每次用到这个字母的时候，先标记一下，这里是用 * 标记，后面的搜索遇到这个标记就退出，保证只用一次。


### 代码

```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function (board, word) {
  const W = board.length;
  const H = board[0].length
  const K = word.length

  //搜索的方向
  const dirs = [[0, -1], [1, 0],[0, 1],[-1, 0]]
  function helper(i, j, k) {
    if (k>=K) return true
    if (i >= W || j >= H || i < 0 || j < 0) return false

    if (board[i][j] !== word[k]) return false
    board[i][j]='*'
    for (let [x,y] of dirs) {
      if(helper(i+x,j+y,k+1)) return true
    }
    board[i][j]=word[k]
    return false
  }
  for (let i = 0; i < W; i++) {
    for (let j = 0; j < H; j++) {
      if (helper(i,j,0)) return true
    }
  }
  return false
};
```

### 思考

如果每个单词可以用` n `次，怎么修改？

`board[i][j]='*'` 这种记录肯定是不行了。可以转换一下

board[i][j]保留，用boardKey[i][j]做为递归之用。boardKey的每个单元值是这个值用过的次数。