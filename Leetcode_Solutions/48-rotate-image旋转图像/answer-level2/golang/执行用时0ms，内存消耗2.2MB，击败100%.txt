### 解题思路
此处撰写解题思路

从外圈到内圈，转圈赋值。可以想象为一个轮子。

### 代码

```golang
func rotate(matrix [][]int) {
	mLen := len(matrix)
	// tmp := make([]int, mLen)
	var tmp int

	if mLen == 0 {
		return
	}

	if len(matrix[0]) == 0 {
		return
	}

	nRound := mLen / 2

	for i := 0; i < nRound; i++ {
		// copy(tmp, matrix[mLen-1-i])

		for j := i; j < mLen-i-1; j++ {

			tmp = matrix[mLen-1-i][j]
			matrix[mLen-1-i][j] = matrix[mLen-j-1][mLen-1-i]
			matrix[mLen-j-1][mLen-1-i] = matrix[i][mLen-j-1]
			matrix[i][mLen-j-1] = matrix[j][i]
			matrix[j][i] = tmp

		}

	}
}
```