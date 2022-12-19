### 解题思路
动态规划，动态数组假设为 matrix[len(word1)+1][len(word2)+1]
1. 如果 word1[i] == word2[j] 那么 matrix[i][j] = matrix[i-1][j-1]
2. 否则 matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1

### 代码

```golang

func minDistance(word1 string, word2 string) int {
	if len(word1) == 0 {
		return len(word2)
	}

	if len(word2) == 0 {
		return len(word1)
	}

	matrix := make([][]int, len(word1)+1)

	for i := 0; i < len(matrix); i++ {
		matrix[i] = make([]int, len(word2)+1)
	}

	for i := 0; i < len(word1)+1; i++ {
		matrix[i][0] = i
	}

	for i := 0; i < len(word2)+1; i++ {
		matrix[0][i] = i
	}

	if word1[0] == word2[0] {
		matrix[1][1] = 0
	} else {
		matrix[1][1] = 1
	}

	for i := 1; i < len(matrix); i++ {
		for j := 1; j < len(matrix[i]); j++ {
			if word1[i-1] == word2[j-1] {
				matrix[i][j] = matrix[i-1][j-1]
			} else {
				matrix[i][j] = minNode(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1
			}
		}
	}

	return matrix[len(word1)][len(word2)]
}

func minNode(a, b, c int) int {
	var min = math.MaxInt32

	if a < min {
		min = a
	}

	if b < min {
		min = b
	}

	if c < min {
		min = c
	}

	return min
}
```