### 解题思路
这阅读理解题，记住是所有细胞同时变更状态，那么如果广度或者深度遍历的方式会导致判断起来很麻烦
1. 我们里完全可以简化操作，获取每个元素上下左右的节点状态，得出当前元素的状态，把新状态重新存进二维数组
2. 这里 golang 不要求返回新二维数组而是想让我们在原二维数组上直接修改，直接把得到的新二维数组赋值过去是不正确的，需要为原数组的每一个元素重新赋值才可以

### 代码

```golang

func gameOfLife(board [][]int) {
	var ret [][]int
	for i := 0; i < len(board); i++ {
		var line []int
		for j := 0; j < len(board[i]); j++ {
			line = append(line, calcState(i, j, board))
		}
		ret = append(ret, line)
	}
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[i]); j++ {
			board[i][j] = ret[i][j]
		}
	}
}

func calcState(i int, j int, board [][]int) int {
	var live int
	// 左边
	if i-1 >= 0 {
		if j-1 >= 0 {
			if board[i-1][j-1] == 1 {
				live++
			}
		}
		if j+1 < len(board[i]) {
			if board[i-1][j+1] == 1 {
				live++
			}
		}
		if board[i-1][j] == 1 {
			live++
		}
	}
	// 右边
	if i+1 < len(board) {
		if j-1 >= 0 {
			if board[i+1][j-1] == 1 {
				live++
			}
		}
		if j+1 < len(board[i]) {
			if board[i+1][j+1] == 1 {
				live++
			}
		}
		if board[i+1][j] == 1 {
			live++
		}
	}
	// 上边
	if j-1 >= 0 {
		if board[i][j-1] == 1 {
			live++
		}
	}
	// 下边
	if j+1 < len(board[i]) {
		if board[i][j+1] == 1 {
			live++
		}
	}

	if board[i][j] == 1 {
		if live < 2 || live > 3 {
			return 0
		} else {
			return 1
		}
	} else {
		if live == 3 {
			return 1
		} else {
			return 0
		}
	}
}
```