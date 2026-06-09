### 解题思路
![image.png](https://pic.leetcode-cn.com/b6cd1421c36e7ec9ebb0935d7fd06fd53282a9b71a730f76ebba3b84f9d1271e-image.png)

### 代码

```golang
//先找出R的位置
//然后判断它的四个方向
//遇到白象 就停止
//遇到第一个黑色的卒 结果+1 停止
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

//北
for i:=y;i>=0;i-- {
    if board[x][i] == byte('p') {
        sum++
        break
    }

    if board[x][i] == byte('B') {
        break;
    }
}

//东
for i:=x;i<8;i++ {
    if board[i][y] == byte('p') {
        sum++
        break
    }

    if board[i][y] == byte('B') {
        break;
    }
}
//西
for i:=x-1;i>=0;i-- {
    if board[i][y] == byte('p') {
        sum++
        break
    }

    if board[i][y] == byte('B') {
        break;
    }
}

//南
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