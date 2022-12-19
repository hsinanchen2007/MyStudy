```
func sortArrayByParity(A []int) []int {
    for i := 0; i < len(A)-1; i++ {
		if A[i]%2 == 0 {
			continue
		}
		for j := i + 1; j < len(A); j++ {
			if A[j]%2 == 0 {
				A[i], A[j] = A[j], A[i]
				break
			}
		}
	}

	return A
}
```