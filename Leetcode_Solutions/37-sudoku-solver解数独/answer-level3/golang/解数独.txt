## 结果

![image.png](https://pic.leetcode-cn.com/9f1129969a33daa814bb809e022d25acc54ab46c85e0bae497af5e4f8e76efa9-image.png)

## 思路

首先根据规则搜索填充，发现无法满足所有的用例，搜索填充后再使用回溯法


```
func solveSudoku(board [][]byte) {
	lines := makeMaps()
	cols := makeMaps()
	blocks := makeMaps()

	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] != '.' {
				v := int(board[i][j]) - int('0')
				lines[i][v] = true
				cols[j][v] = true
				blocks[i/3*3+j/3][v] = true
			}
		}
	}

search:
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] == '.' {
				// search
				mp := make(map[int]bool)
				for k, v := range lines[i] {
					if v {
						mp[k] = true
					}
				}
				for k, v := range cols[j] {
					if v {
						mp[k] = true
					}
				}
				for k, v := range blocks[i/3*3+j/3] {
					if v {
						mp[k] = true
					}
				}
				buf := []int{}
				for k := 1; k < 10; k++ {
					if !mp[k] {
						buf = append(buf, k)
					}
				}
				if len(buf) == 1 {
					board[i][j] = byte(buf[0] + '0')

					lines[i][buf[0]] = true
					cols[j][buf[0]] = true
					blocks[i/3*3+j/3][buf[0]] = true
					goto search
				}
				
			}
		}
	}

	next(board, lines, cols, blocks)
	showBoard(board)

}

func next(board [][]byte, lines, cols, blocks []map[int]bool) bool {
	// 开始回溯
	f := true
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] == '.' {
				bi := i/3*3 + j/3
				for c := 1; c < 10; c++ {
					if !lines[i][c] && !cols[j][c] && !blocks[bi][c] {
						f = false
						board[i][j] = byte(c + '0')
						lines[i][c] = true
						cols[j][c] = true
						blocks[bi][c] = true
						if next(board, lines, cols, blocks) {
							return true
						} else {
							board[i][j] = '.'
							lines[i][c] = false
							cols[j][c] = false
							blocks[bi][c] = false
						}
					}
				}
				return false
			}

		}
	}
	return f
}

func showBoard(board [][]byte) {
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] == '.' {
				fmt.Print("  ", "X")
			} else {
				fmt.Print("  ", board[i][j]-'0')
			}
		}
		fmt.Println()
	}
}

func makeMaps() []map[int]bool {
	mps := make([]map[int]bool, 9)
	for i := 0; i < 9; i++ {
		mps[i] = make(map[int]bool)
	}
	return mps
}

```

