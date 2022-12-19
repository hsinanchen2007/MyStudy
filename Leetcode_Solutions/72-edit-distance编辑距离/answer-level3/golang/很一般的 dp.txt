```
func minDistance(word1 string, word2 string) int {
	var (
		len1             = len(word1)
		len2             = len(word2)
		distince [][]int = make([][]int, len1+1)
	)

	if len1 == 0 || len2 == 0 {
		return len2 + len1
	}

	// distince[x][y] = minDistance(word1[x:], word2[y:])
	for i := 0; i <= len1; i++ {
		distince[i] = make([]int, len2+1)
		distince[i][len2] = len1 - i
	}
	for i := 0; i <= len2; i++ {
		distince[len1][i] = len2 - i
	}

	for i := len1 - 1; i >= 0; i-- {
		for j := len2 - 1; j >= 0; j-- {
			if word1[i] == word2[j] {
				distince[i][j] = distince[i+1][j+1]
			} else {
				min1 := distince[i+1][j]
				min2 := distince[i][j+1]
				min3 := distince[i+1][j+1]

				var min = min1
				if min2 < min {
					min = min2
				}
				if min3 < min {
					min = min3
				}
				distince[i][j] = min + 1
			}
		}
	}

	return distince[0][0]
}
```
