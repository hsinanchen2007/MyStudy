### 解题思路
这里是用迭代的方法来解决问题，速度不好

### 代码

```golang
type SudokuInfo struct {
	rowMap map[int]map[byte]int
	colMap map[int]map[byte]int
	boxMap map[int]map[byte]int
	value [][]byte
}

func (s *SudokuInfo) InitInfo(board [][]byte) {
	s.value = board
	s.rowMap = make(map[int]map[byte]int)
	s.colMap = make(map[int]map[byte]int)
	s.boxMap = make(map[int]map[byte]int)

	for i := 0; i < 9; i++ {
		s.rowMap[i] = make(map[byte]int)
		s.colMap[i] = make(map[byte]int)
		s.boxMap[i] = make(map[byte]int)
	}

	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			boxIdx := (i / 3) * 3 + j / 3

			if s.value[i][j] == '.' {
				s.rowMap[i][s.value[i][j]] = 0
				s.colMap[j][s.value[i][j]] = 0
				s.boxMap[boxIdx][s.value[i][j]] = 0
			} else {
				s.rowMap[i][s.value[i][j]] = 1
				s.colMap[j][s.value[i][j]] = 1
				s.boxMap[boxIdx][s.value[i][j]] = 1
			}
		}
	}
}

func (s *SudokuInfo) GetBoxIdx(row, col int) int {
	return (row / 3) * 3 + col / 3
}

func (s *SudokuInfo) CanSetValue(row, col int, value byte) bool {
	return s.rowMap[row][value] + s.colMap[col][value] + s.boxMap[s.GetBoxIdx(row, col)][value] == 0
}

func (s *SudokuInfo) PlaceValue(row, col int, value byte) {
	s.rowMap[row][value] = 1
	s.colMap[col][value] = 1
	s.boxMap[s.GetBoxIdx(row, col)][value] = 1
	s.value[row][col] = value
}

func (s *SudokuInfo) DeleteValue(row, col int, value byte) {
	s.rowMap[row][value] = 0
	s.colMap[col][value] = 0
	s.boxMap[s.GetBoxIdx(row, col)][value] = 0
	s.value[row][col] = '.'
}

func (s *SudokuInfo)FillNextValue(row, col int) bool {
	if row == 8 && col == 8 {
		return true
	}
	if col == 8 {
		return s.FillSudokuInfo(row + 1, 0)
	} else {
		return s.FillSudokuInfo(row, col + 1)
	}
}

func (s *SudokuInfo) FillSudokuInfo(row, col int) bool {
	if s.value[row][col] == '.' {
		setSuccess := false
		for i := 0; i < 9; i++ {
			setByte := byte('1' + i)
			if s.CanSetValue(row, col, setByte) == true {
				setSuccess = true
				s.PlaceValue(row, col, setByte)

				if s.FillNextValue(row, col) == false {
					setSuccess = false
					s.DeleteValue(row, col, setByte)
				}
			}
			if setSuccess == true {
				break
			}
		}
		return setSuccess
	} else {
		return s.FillNextValue(row, col)
	}
}

func solveSudoku(board [][]byte) {
	sudoku := new(SudokuInfo)
	sudoku.InitInfo(board)

	sudoku.FillSudokuInfo(0, 0)
}
```


按点赞最多的思路，还没有上面速度快，在找到合适的字符后没有退出，接着往下比较了；
不过优化了那里后，速度还是没有上面的快，还要再看看有哪里可以提速的
```
type SudokuInfo struct {
	rowMap map[int]map[byte]int
	colMap map[int]map[byte]int
	boxMap map[int]map[byte]int
	value [][]byte
	sudokuSolved bool
}

func (s *SudokuInfo) InitInfo(board [][]byte) {
	s.value = board
	s.rowMap = make(map[int]map[byte]int)
	s.colMap = make(map[int]map[byte]int)
	s.boxMap = make(map[int]map[byte]int)

	for i := 0; i < 9; i++ {
		s.rowMap[i] = make(map[byte]int)
		s.colMap[i] = make(map[byte]int)
		s.boxMap[i] = make(map[byte]int)
	}

	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			boxIdx := (i / 3) * 3 + j / 3

			if s.value[i][j] == '.' {
				s.rowMap[i][s.value[i][j]] = 0
				s.colMap[j][s.value[i][j]] = 0
				s.boxMap[boxIdx][s.value[i][j]] = 0
			} else {
				s.rowMap[i][s.value[i][j]] = 1
				s.colMap[j][s.value[i][j]] = 1
				s.boxMap[boxIdx][s.value[i][j]] = 1
			}
		}
	}
}

func (s *SudokuInfo) ShowValue () {
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			fmt.Printf("%3c", s.value[i][j])
		}
		fmt.Printf("\n")
	}
}

func (s *SudokuInfo) GetBoxIdx(row, col int) int {
	return (row / 3) * 3 + col / 3
}

func (s *SudokuInfo) CanSetValue(row, col int, value byte) bool {
	return s.rowMap[row][value] + s.colMap[col][value] + s.boxMap[s.GetBoxIdx(row, col)][value] == 0
}

func (s *SudokuInfo) PlaceValue(row, col int, value byte) {
	s.rowMap[row][value] = 1
	s.colMap[col][value] = 1
	s.boxMap[s.GetBoxIdx(row, col)][value] = 1
	s.value[row][col] = value
}

func (s *SudokuInfo) DeleteValue(row, col int, value byte) {
	s.rowMap[row][value] = 0
	s.colMap[col][value] = 0
	s.boxMap[s.GetBoxIdx(row, col)][value] = 0
	s.value[row][col] = '.'
}

func (s *SudokuInfo)FillNextValue(row, col int) {
	if row == 8 && col == 8 {
		s.sudokuSolved = true
	} else if col == 8 {
		s.FillSudokuInfo(row + 1, 0)
	} else {
		s.FillSudokuInfo(row, col + 1)
	}
}

func (s *SudokuInfo) FillSudokuInfo(row, col int) {
	if s.value[row][col] == '.' {
		for i := 0; i < 9; i++ {
			setByte := byte('1' + i)
			if s.CanSetValue(row, col, setByte) == true {
				s.PlaceValue(row, col, setByte)
				s.FillNextValue(row, col)

				if s.sudokuSolved == false {
					s.DeleteValue(row, col, setByte)
				} else {
					break // 这里要break出来，因为已经找到合适的了
				}
			}
		}
	} else {
		s.FillNextValue(row, col)
	}
}

func solveSudoku(board [][]byte) {
	sudoku := new(SudokuInfo)
	sudoku.InitInfo(board)

	sudoku.FillSudokuInfo(0, 0)
}
```

把map改为slice，时间和空间都变得好了，但还是没有达到预期效果
```
type SudokuInfo struct {
	rowMap map[int][]int
	colMap map[int][]int
	boxMap map[int][]int
	value [][]byte
}

func (s *SudokuInfo) InitInfo(board [][]byte) {
	s.value = board
	s.rowMap = make(map[int][]int)
	s.colMap = make(map[int][]int)
	s.boxMap = make(map[int][]int)

	for i := 0; i < 9; i++ {
		s.rowMap[i] = []int{0, 0, 0, 0, 0, 0, 0, 0, 0}
		s.colMap[i] = []int{0, 0, 0, 0, 0, 0, 0, 0, 0}
		s.boxMap[i] = []int{0, 0, 0, 0, 0, 0, 0, 0, 0}
	}

	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			boxIdx := (i / 3) * 3 + j / 3

			if s.value[i][j] != '.' {
				idx := int(s.value[i][j] - '1')
				s.rowMap[i][idx] = 1
				s.colMap[j][idx] = 1
				s.boxMap[boxIdx][idx] = 1
			}
		}
	}
}

func (s *SudokuInfo) GetBoxIdx(row, col int) int {
	return (row / 3) * 3 + col / 3
}

func (s *SudokuInfo) CanSetValue(row, col int, value byte) bool {
	idx := int(value - '1')
	return s.rowMap[row][idx] + s.colMap[col][idx] + s.boxMap[s.GetBoxIdx(row, col)][idx] == 0
}

func (s *SudokuInfo) PlaceValue(row, col int, value byte) {
	idx := int(value - '1')
	s.rowMap[row][idx] = 1
	s.colMap[col][idx] = 1
	s.boxMap[s.GetBoxIdx(row, col)][idx] = 1
	s.value[row][col] = value
}

func (s *SudokuInfo) DeleteValue(row, col int, value byte) {
	idx := int(value - '1')
	s.rowMap[row][idx] = 0
	s.colMap[col][idx] = 0
	s.boxMap[s.GetBoxIdx(row, col)][idx] = 0
	s.value[row][col] = '.'
}

func (s *SudokuInfo)FillNextValue(row, col int) bool {
	if row == 8 && col == 8 {
		return true
	}
	if col == 8 {
		return s.FillSudokuInfo(row + 1, 0)
	} else {
		return s.FillSudokuInfo(row, col + 1)
	}
}

func (s *SudokuInfo) FillSudokuInfo(row, col int) bool {
	if s.value[row][col] == '.' {
		setSuccess := false
		for i := 0; i < 9; i++ {
			setByte := byte('1' + i)
			if s.CanSetValue(row, col, setByte) == true {
				setSuccess = true
				s.PlaceValue(row, col, setByte)

				if s.FillNextValue(row, col) == false {
					setSuccess = false
					s.DeleteValue(row, col, setByte)
				}
			}
			if setSuccess == true {
				break
			}
		}
		return setSuccess
	} else {
		return s.FillNextValue(row, col)
	}
}

func solveSudoku(board [][]byte) {
	sudoku := new(SudokuInfo)
	sudoku.InitInfo(board)

	sudoku.FillSudokuInfo(0, 0)
}
```
