### 解题思路
动态定义二维数组的方式如下：board_exp := make([][]int, 0) 然后使用append数组进来的形式来定义

### 代码

```golang
func gameOfLife(board [][]int)  {
if len(board)<1{
  return
 }
 row:=len(board)
 col:=len(board[0])
 board_exp := make([][]int, 0)
 for i := 0; i < row; i++ {
  t := make([]int, 0)
  for j:=0;j<col;j++  {
   t = append(t, board[i][j])
  }
  board_exp = append(board_exp, t)
 }

for i:=0;i<len(board);i++{
 for j:=0;j<len(board[0]);j++  {
  if board[i][j]==0{
   if numOf8Grid(board_exp,i,j)==3{
    board[i][j]=1
   }
  }else{
   if numOf8Grid(board_exp,i,j)<2 || numOf8Grid(board_exp,i,j)>3{
    board[i][j]=0
   }
  }
 }
}
}
func numOf8Grid(board [][]int,i int,j int) int{
 cnt:=0
 DX := []int{0, 0, 1, -1, 1, 1, -1, -1}
 DY := []int{1, -1, 0, 0, 1, -1, 1, -1};
 for k:= 0; k < 8; k++ {
   x := i + DX[k];
   y:= j + DY[k];
  if (x < 0 || x >= len(board) || y < 0 || y >= len(board[0])) {
   continue;
  }
  // 这里不能直接加board[x][y]，因为 board[x][y] 的倒数第二位是可能有值的。
  cnt += board[x][y];
 }
 return cnt
}
```