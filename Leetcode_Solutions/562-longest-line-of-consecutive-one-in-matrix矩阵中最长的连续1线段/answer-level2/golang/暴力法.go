### 解题思路
此处撰写解题思路

### 代码

```golang

func longestLine(M [][]int) int {
	r := len(M)
	if r == 0 {
		return 0
	}
	c := len(M[0])
	num := 0
	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			if M[i][j] == 0 {
				continue
			}
			n := find(M, i, j)
			if num < n {
				num = n
			}
		}
	}

	return num
}

func find(M [][]int, i, j int) int {
	numRow := findRow(M, i, j)
	numCol := findCol(M, i, j)
	numLeft := findLeft(M, i, j)
	numRight := findRight(M, i, j)
	max1 := math.Max(float64(numRow), float64(numCol))
	max2 := math.Max(float64(numLeft), float64(numRight))
	return int(math.Max(max1, max2))
}

func findRow(M [][]int, i int, j int) int {
	num := 1
	for m := j + 1; m < len(M[0]); m++ {
		if M[i][m] == 0 {
			break
		}
		num++
	}
	for n := j - 1; n >= 0; n-- {
		if M[i][n] == 0 {
			break
		}
		num++
	}
	return num
}

func findCol(M [][]int, i int, j int) int {
	num := 1
	for m := i + 1; m < len(M); m++ {
		if M[m][j] == 0 {
			break
		}
		num++
	}

	for n := i - 1; n >= 0; n-- {
		if M[n][j] == 0 {
			break
		}
		num++
	}
	return num
}

func findLeft(M [][]int, i int, j int) int {
	num := 1
	for m := i + 1; m < len(M); m++ {
		if j-(m-i) >= 0 {
			if M[m][j-(m-i)] == 1 {
				num++
			} else {
				break
			}
		} else {
			break
		}
	}

	for n := i - 1; n >= 0; n-- {
		if j+(i-n) < len(M[0]) {
			if M[n][j+(i-n)] == 1 {
				num++
			} else {
				break
			}
		} else {
			break
		}

	}
	return num
}

func findRight(M [][]int, i int, j int) int {
	num := 1

	for m := i + 1; m < len(M); m++ {
		if j+(m-i) < len(M[0]) {
			if M[m][j+(m-i)] == 1 {
				num++
			} else {
				break
			}
		} else {
			break
		}

	}

	for n := i - 1; n >= 0; n-- {
		if j-(i-n) >= 0 {
			if M[n][j-(i-n)] == 1 {
				num++
			} else {
				break
			}
		} else {
			break
		}

	}
	return num
}

```