一、数组判断
```javascript []
function solveNQueens(n) {
  var answers = [],
    ld_last = [], //左斜线 \ ， col-row
    rd_list = [], //右斜线 / ， row+col
    col_list = [], //列
    queens = []
  function isNotUnderAttack(row, col) {
    return !col_list[col] && !ld_last[col - row] && !rd_list[row + col]
  }
  function placeQueen(row, col) {
    queens.push(col)
    col_list[col] = true
    ld_last[col - row] = true
    rd_list[row + col] = true
  }
  function removeQueen(row, col) {
    queens.pop(col)
    col_list[col] = false
    ld_last[col - row] = false
    rd_list[row + col] = false
  }
  function addSolution() {
    var answer = []
    for (let i = 0; i < n; ++i) {
      let col = queens[i], sb = '';
      for (let j = 0; j < col; ++j) sb += '.';
      sb += 'Q'
      for (let j = 0; j < n - col - 1; ++j) sb += '.';
      answer.push(sb)
    }
    answers.push(answer)
  }
  function backtrack(row) {
    for (var col = 0; col < n; col++) {
      if (isNotUnderAttack(row, col)) {
        placeQueen(row, col);
        if (row + 1 == n) addSolution();
        else backtrack(row + 1);
        removeQueen(row, col);
      }
    }
  }

  backtrack(0)
  return answers
}
```
二、位运算判断

使用 n 位的二进制存储，以 `1100` 为例子，表示1、2格子不能放置，3、4格子可放置皇后

```javascript []
function solveNQueens(n) {
  /* 
    ld 左斜线 \  位数为n的二进制数字，1表示已经被占用（不可放置）
    rd 右斜线 /  
    col 列   |  
    upperlim 可以放置的位置  n个1 ，例 n=4 --> 1111
  */

  var answers = [],
    upperlim = (1 << n) - 1,
    queens = []

  function addSolution() {
    var answer = []
    for (let i = 0; i < n; ++i) {
      let col = queens[i], sb = '';
      for (let j = 0; j < col; ++j) sb += '.';
      sb += 'Q'
      for (let j = 0; j < n - col - 1; ++j) sb += '.';
      answer.push(sb)
    }
    answers.push(answer)
  }

  function backtrack(col, ld, rd) {
    if (col === upperlim) {
      addSolution()
    } else {
      /* 
        pos 当前可以摆放的位置 
        例：n=4，第一行第二列摆放了皇后 (.Q..)
           那么第二行限制为
              col 0100    
              ld  0010
              rd  1000
           合并限制    col | ld | rd = 1110
           可摆放位置 （~ 会转成32位的反码，这里只需要 n 位，所以 upperlim & 舍去多余的位数）
              pos = ~(col | ld | rd) = 0001 
           当 pos>0 , 说明有位置摆放皇后
      */
      var pos = upperlim & ~(col | ld | rd)
      while (pos) {
        /* 
          current 当前摆放皇后的位置，从右往做取第一个 1
          ① 取反~，0转1，1转0 ，                        ~ 0001      = 1110
          ② +1，通过二进制加法 把变成 0 的 1 重新转成 1    1110 + 1    = 1111
          ③ pos & ，取得第一个 1，                      0001 & 0001 = 0001
        */
        var current = pos & (~pos + 1)
        pos -= current
        queens.push(n - 1 - Math.log2(current))
        /* 
          列：    col | current （ col + current 也可以 ）
          左斜线： ld | current 再 右移 一位
          右斜线： rd | current 再 左移 一位
        */
        backtrack(col | current, upperlim & (ld | current) >> 1, upperlim & (rd | current) << 1)
        queens.pop()
      }
    }
  }

  backtrack(0, 0, 0)
  return answers
}
```