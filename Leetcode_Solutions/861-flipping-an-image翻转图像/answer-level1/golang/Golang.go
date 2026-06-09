```

func flipAndInvertImage(A [][]int) [][]int {
	for i, row := range A {
		for j := range row {
			if j > (len(row)-1)/2 {
				break
			}

			tmp := A[i][j]
			A[i][j] = A[i][len(row)-1-j]
			A[i][len(row)-1-j] = tmp

			A[i][j] = A[i][j] ^ 1
			if len(row)-1-j != j {
				A[i][len(row)-1-j] = A[i][len(row)-1-j] ^ 1
			}

		}
	}
	return A
}
```