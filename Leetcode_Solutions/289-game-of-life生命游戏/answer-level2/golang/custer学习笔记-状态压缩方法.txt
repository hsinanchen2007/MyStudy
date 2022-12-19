### 解题思路
学习自[花花酱视频](http://zxi.mytechroad.com/blog/simulation/leetcode-289-game-of-life/)


### 代码

```golang
func gameOfLife(board [][]int)  {
  m := len(board) // m 行
  n := 0 // n 列
  if m != 0 {
    n = len(board[0])
  }
  for i := 0; i < m; i++ {
    for j := 0; j < n; j++ {
      lives := 0 // 统计有多少是存活的
      // Scan the 3x3 region including (j, i).
      // 以(j,i)为中心点，扫描3x3的区间  y=[i-1,i+1] x=[j-1,j+1]
      for y := max(0, i-1); y < min(m, i+2); y++ {
        for x := max(0,j-1); x < min(n, j+2); x++ { 
          lives += board[y][x] & 1 // 和最低位相与拿到状态是否存活着
        }
      }
      // 状态压缩
      if lives == 3 || (lives - board[i][j]) == 3 {
        board[i][j] |= 0b10 // 该位置存活或复活，倒数第一位置为1，表明下一刻是存活的
      }
    }
  }
  // 重新扫描一遍，右移一位
  for i:= 0; i < m; i++ {
    for j:= 0; j < n; j++ {
      board[i][j] >>= 1
    }
  }
}

func min(a, b int) int{
  if a < b {
    return a
  }
  return b
}

func max(a, b int)int{
  if a< b{
    return b
  }
  return a
}
```