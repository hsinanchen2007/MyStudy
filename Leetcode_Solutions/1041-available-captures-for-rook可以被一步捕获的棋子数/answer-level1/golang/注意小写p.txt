### 解题思路
四个方向找p，注意小写

### 代码

```golang
func numRookCaptures(board [][]byte) int {
  // 查找R
  var x,y int
  sum:=0
  for i:=0;i<8;i++{
    for j:=0;j<8;j++{
      if board[i][j] == byte('R'){
        x,y = i,j
        break
      }
    }
  }
  fmt.Println(x,y)
  for i:=x;i>=0;i--{
    if board[i][y] == byte('p'){
      sum ++
      break
    }
    if board[i][y] == byte('B'){
      break
    }
  }
  fmt.Println(sum)
  for i:=x;i<8;i++{
    fmt.Println(i,y,board[i][y])
    if board[i][y] == byte('p'){
      sum ++
      break
    }
    if board[i][y] == byte('B'){
      break
    }
  }
  fmt.Println(sum)
  for j:=y;j>=0;j--{
    if board[x][j] == byte('p'){
      sum ++
      break
    }
    if board[x][j] == byte('B'){
      break
    }
  }
  fmt.Println(sum)
  for j:=y;j<8;j++{
    if board[x][j] == byte('p'){
      sum ++
      break
    }
    if board[x][j] == byte('B'){
      break
    }
  }

  return sum

}
```