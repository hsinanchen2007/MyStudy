### 解题思路
此处撰写解题思路

### 代码

```golang
type tuple struct {
	x int
	y int
}

func gameOfLife(board [][]int) {
	rows := len(board)
	if rows == 0{return}
	cols := len(board[0])
	store := make(map[tuple]int)
	for r, arr := range board {
		for c, v := range arr {
			liveCells := 0
			cellAround := []tuple{
				tuple{r - 1, c - 1},
				tuple{r - 1, c},
				tuple{r - 1, c + 1},
				tuple{r, c - 1},
				tuple{r, c + 1},
				tuple{r + 1, c - 1},
				tuple{r + 1, c},
				tuple{r + 1, c + 1},
			}
			for _, around := range cellAround {
				if around.x < 0 || around.y < 0 || around.x >= rows || around.y >= cols{
					continue
				}
				if board[around.x][around.y] == 1 {
					liveCells++
				}
			}
			curCellPos := tuple{r, c}
			if v == 1{
				if liveCells<2 || liveCells>3{
					store[curCellPos] = 0
				}
			} else {
				if liveCells == 3{
					store[curCellPos] = 1
				}
			}
		}
	}
	for i, v:=range store{
		board[i.x][i.y] = v
	}
}

```