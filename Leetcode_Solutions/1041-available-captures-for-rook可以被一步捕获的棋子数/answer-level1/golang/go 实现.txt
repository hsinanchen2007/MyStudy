```
func numRookCaptures(board [][]byte) int {
	var (
		cnt, start, end int
		//x y 坐标
		dx = []int{0, 1, 0, -1}
		dy = []int{1, 0, -1, 0}
	)
	//找到白色车的下标 
	for i := 0; i < 8; i++ {
		for j := 0; j < 8; j++ {
			if board[i][j] == 'R' {
				start = i
				end = j
				break
			}
		}
	}
	//1 确定4个方向
	for i := 0; i < 4; i++ {
		//横向的长度
		for step := 0; step < 8; step++ {
			tx := start + step*dx[i]
			ty := end + step*dy[i]
			if tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B' {
				break
			}
			if board[tx][ty] == 'p' {
				cnt++
				break
			}
		}
	}
	return cnt
}
```
