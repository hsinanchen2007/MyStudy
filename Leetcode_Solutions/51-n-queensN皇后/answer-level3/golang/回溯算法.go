```
func solveNQueens(n int) [][]string {
	queues := [][]string{}
	res := make([]int, n)
	calcQueues(0, n, res, &queues)
	return queues
}

func calcQueues(row, n int, res []int, queues *[][]string) {
	if row >= n {
		q := printQ(res, n)
		*queues = append(*queues, q)
		return
	}
	for col := 0; col < n; col++ {
		if isOK(row, col, n, res) {
			res[row] = col
			calcQueues(row+1, n, res, queues)
		}
	}
}

func isOK(row, col, n int, res []int) bool {
	leftup := col - 1
	rightup := col + 1
	for i := row - 1; i >= 0; i-- {
		if res[i] == col {
			return false
		}
		if leftup >= 0 && res[i] == leftup {
			return false
		}
		if rightup < n && res[i] == rightup {
			return false
		}
		leftup--
		rightup++
	}
	return true
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
