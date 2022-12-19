```
func solveNQueens(n int) [][]string {
	queues := [][]string{}
	res := make([]int, n)
	rows := make([]int, n)
    hills := make([]int, n*4-1)
    dales := make([]int, n*2-1)
    backtrace(0, n, res, &queues, rows, hills, dales)
	return queues
}

func backtrace(row, n int, res []int, queues *[][]string, rows, hills, dales []int){
    if row >= n {
		q := printQ(res, n)
		*queues = append(*queues, q)
		return
	}
    for col := 0; col < n; col++ {
		if isNotUnderAttack(row, col, rows, hills, dales, n) {
            placeQueue(row, col, res, rows, hills, dales, n)
			backtrace(row+1, n, res, queues, rows, hills, dales)
            removeQueue(row, col, res,rows, hills, dales, n)
		}
	}
}

func isNotUnderAttack(row, col int, rows, hills, dales []int, n int) bool {
    ret := rows[col] + hills[row - col + 2*n] + dales[row + col]
    if ret == 0 {
        return true
    } else {
        return false
    }
}

func placeQueue(row, col int, res, rows, hills, dales []int, n int) {
    res[row] = col
    rows[col] = 1
    hills[row-col+2*n] = 1
    dales[row+col]=1
    
}

func removeQueue(row, col int, res, rows, hills, dales []int, n int) {
    res[row] = 0
    rows[col] = 0
    hills[row-col+2*n] = 0
    dales[row+col]=0
    
}


func printQ(res []int, n int) []string {
	s := []string{}
	for _, v := range res {
		str := ""
		for i := 0; i < n; i++ {
			if i == v {
				str += "Q"
			} else {
				str += "."
			}
		}
		s = append(s, str)
	}
	return s
}
```
