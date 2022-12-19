```
var (
    m = make(map[int]int)
    b = [][]int{{1,2,3}, {4,5,0}}
)

func init() {
    initMap(b, 0, 1, 2)
}

func newSlice(board [][]int) [][]int {
    tmp := make([][]int, 2)
	tmp[0] = make([]int, 3)
	copy(tmp[0], board[0])
	tmp[1] = make([]int, 3)
	copy(tmp[1], board[1])
    return tmp
}

func initMap(board [][]int, step, i, j int) {
    key := parseInt(board)
    if old, ok := m[key]; ok {
        if step >= old {
            return   
        }
    }
    m[key] = step
    if i > 0 {
        tmp := newSlice(board)
		tmp[i][j], tmp[i-1][j] = tmp[i-1][j], tmp[i][j]
		initMap(tmp, step + 1, i-1, j)
	}

	if i < 1 {
        tmp := newSlice(board)
		tmp[i][j], tmp[i+1][j] = tmp[i+1][j], tmp[i][j]
		initMap(tmp, step + 1, i+1, j)
	}

	if j > 0 {
        tmp := newSlice(board)
		tmp[i][j], tmp[i][j-1] = tmp[i][j-1], tmp[i][j]
		initMap(tmp, step + 1, i, j-1)
	}

	if j < 2 {
        tmp := newSlice(board)
		tmp[i][j], tmp[i][j+1] = tmp[i][j+1], tmp[i][j]
		initMap(tmp, step + 1, i, j+1)
	}
}

func parseInt(board [][]int) int {
    val := 0
    for i := 0; i < len(board); i++ {
        for j := 0; j < len(board[0]); j++ {
            val = val * 10 + board[i][j] 
        }
    }
    return val
}

func slidingPuzzle(board [][]int) int {
    val := parseInt(board)
	if step, ok := m[val]; ok {
		return step
	}
	return -1
}
```
