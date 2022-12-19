首先我们考虑如何通过idx获取board的下标
横坐标很好计算，就是倒过来 。纵坐标的话需要考虑奇偶。如果横坐标正过来的偶数。那么就是余数。反之则要倒过来。这里要记得加n取余，具体看代码：
```
func getIdx(idx int, n int) (i int,j int) {
	i = n - 1 - (idx-1)/n
	if (n - 1 - i)%2 == 0 {
		j = (idx%n + n - 1)%n
	} else {
		j = (n - idx%n)%n
	}
	return
}
```
个人认为这题的关键就是计算坐标，之后的dfs就很简单了。用二维数组记录到达该坐标的最小步数即可。
```
func snakesAndLadders(board [][]int) int {
    minReach := make([][]int, len(board))
    for i := 0; i < len(minReach); i++ {
	minReach[i] = make([]int, len(board[0]))
    }
    minReach[len(board)-1][0] = 1
    min := 2 << 31
    dfs(1, 0, len(board), &min, board, minReach)
    if min == 2 << 31 {
        return -1
    }
	return min
}

func dfs(idx, step, n int, min *int, board [][]int, minReach [][]int) {
    if step >= *min {
        return
    }
    if idx >= n * n {
		if *min > step {
			*min = step
		}
		return
	}
	x, y := getIdx(idx, n)
	if board[x][y] != -1 {
		idx = board[x][y]
	}
	if idx >= n * n {
		if *min > step {
			*min = step
		}
		return
	}
	x, y = getIdx(idx, n)
	if minReach[x][y] > 0 && minReach[x][y] <= step {
		return
	}
	minReach[x][y] = step
	for i := 1; i <= 6; i++ {
		dfs(idx + i, step + 1, n, min, board, minReach)
	}
	return
}

func getIdx(idx int, n int) (i int,j int) {
	i = n - 1 - (idx-1)/n
	if (n - 1 - i)%2 == 0 {
		j = (idx%n + n - 1)%n
	} else {
		j = (n - idx%n)%n
	}
	return
}

```