### 解题思路

以当前位置为中心，探测周围八个位置，根据规则进行判断细胞的死活。注意：要另外开辟空间，因为细胞都是同时更新的，所有探测都要以原始数组为准，更新结果放在新的数组中，更新结束后再赋给原始数组即可。

### 代码

```golang
func gameOfLife(board [][]int)  {
	direct := []int{-1,0,1}
	res := make([][]int,len(board))
	for i := 0;i < len(board);i++ {
		res[i] = make([]int,len(board[i]))
	}
	for i := 0;i < len(board);i++ {
		for j := 0;j < len(board[0]);j++ {
			count := 0
			for k := 0;k < len(direct);k++ {
				for v := 0;v < len(direct);v++ {
					x := i + direct[k]
					y := j + direct[v]

					if x == i && y == j {
						continue
					}
					if 0 <= x && x < len(board) && 0 <= y && y < len(board[0]) {
						if board[x][y] == 1 {
							count++
						}
					}
				}
			}
			res[i][j] = board[i][j]
			if count < 2 || count > 3 {
				res[i][j] = 0
			}
			if count == 3 {
				res[i][j] =1
			}
		}
	}
	copy(board,res)
}
```