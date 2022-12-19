### 解题思路
题目好长啊。。。
慢慢理清题目其实挺简单的，R走直线遇到B或者边缘就停下，遇到p可以吃掉停下，num+1
所以遍历整个board，当找到R的时候开始进行判断，判断完就可直接return
判断时要注意下标越界问题，要先判断是否等于B，然后判断等于p时num+1，最后返回num

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
      let num = 0
  for (let i = 0; i < 8; i++) {
    for (let j = 0; j < 8; j++) {
      if (board[i][j] == 'R') {
        let m = i
        let n = j
        //i-1 上
        while (--m >= 0) {   
          if (board[m][n] == 'B') break
          if (board[m][n] == 'p') {
            num++
            break
          }
        }
        m = i
        //i+1  下
        while (++m < 8) {
          if (board[m][n] == 'B') break
          if (board[m][n] == 'p') {
            num++
            break
          }
        }
        m = i
        //j-1 左
        while (--n >=0) {
          if (board[m][n] == 'B') break
          if (board[m][n] == 'p') {
            num++
            break
          }
        }
        n = j
        //j+1 右
        while (++n < 8) {
          if (board[m][n] == 'B') break
          if (board[m][n] == 'p') {
            num++
            break
          }
        }

        return num
      }
      
    }
  }
};
```