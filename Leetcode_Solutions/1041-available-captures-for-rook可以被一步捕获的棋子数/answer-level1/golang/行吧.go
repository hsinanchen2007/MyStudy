### 解题思路
此处撰写解题思路

### 代码

```golang
func numRookCaptures(board [][]byte) int {
  var x,y,sum int
  for i:=0;i<8;i++ {
      for j:=0;j<8;j++ {
          if board[i][j] == byte('R') {
              x,y=i,j
              break
          }
      }
  }

for i:=y;i>=0;i-- {
    if board[x][i] == byte('p') {
        sum++
        break
    }

    if board[x][i] == byte('B') {
        break;
    }
}

for i:=x;i<8;i++ {
    if board[i][y] == byte('p') {
        sum++
        break
    }

    if board[i][y] == byte('B') {
        break;
    }
}

for i:=x-1;i>=0;i-- {
    if board[i][y] == byte('p') {
        sum++
        break
    }

    if board[i][y] == byte('B') {
        break;
    }
}

for i:=y+1;i<8;i++ {
    if board[x][i] == byte('p') {
        sum++
        break
    }

    if board[x][i] == byte('B') {
        break;
    }
}
return sum

}
```