### 解题思路
暴力循环 如果有对应符合要求的直接break即可 减少循环次数


### 代码

```golang

func findLonelyPixel(picture [][]byte) int {
	if len(picture) == 0 {
		return 0
	}

	row := len(picture)
	col := len(picture[0])

	count := 0
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if picture[i][j] == 'B' {
				rowFlag := false
				for m := 0; m < row; m++ {
					if m != i && picture[m][j] == 'B' {
						rowFlag = true
					}
				}
				if rowFlag {
					break
				}
				if !rowFlag {
					colFlag := false
					for n := 0; n < col; n++ {
						if n != j && picture[i][n] == 'B' {
							colFlag = true
						}
					}
					if colFlag {
						break
					}
					if !colFlag {
						count += 1
					}
				}

			}

		}
	}

	return count
}

```