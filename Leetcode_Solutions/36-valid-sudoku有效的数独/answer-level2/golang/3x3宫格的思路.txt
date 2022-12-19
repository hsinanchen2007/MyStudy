### 解题思路
这道题目中，唯一的技巧是3*3宫格内的判断，这里借鉴了官方答案中的3x3宫格的思路

### 代码

```golang
func isValidSudoku(board [][]byte) bool {
   	rowMap := make(map[int]map[byte]int)
	columnMap := make(map[int]map[byte]int)
	boxMap := make(map[int]map[byte]int)

	for row := 0; row < 9; row++ {
		for column := 0; column < 9; column++ {
			curByte := board[row][column]
			if curByte == '.' {
				continue
			}

			if _, exist := rowMap[row]; exist == false {
				rowMap[row] = make(map[byte]int)
			}
			if _, exist := rowMap[row][curByte]; exist == true {
				return false
			} else {
				rowMap[row][curByte] = 1
			}

			if _, exist := columnMap[column]; exist == false {
				columnMap[column] = make(map[byte]int)
			}
			if _, exist := columnMap[column][curByte]; exist == true {
				return false
			} else {
				columnMap[column][curByte] = 1
			}

			// 这里借鉴了官方答案中的3x3宫格的思路
			boxIndex := (row / 3) * 3 + column / 3
			if _, exist := boxMap[boxIndex]; exist == false {
				boxMap[boxIndex] = make(map[byte]int)
			}
			if _, exist := boxMap[boxIndex][curByte]; exist == true {
				return false
			} else {
				boxMap[boxIndex][curByte] = 1
			}
		}
	}

	return true 
}
```