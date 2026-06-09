```
func sortArrayByParity(A []int) []int {
	start, end := 0, len(A) - 1
	for ;start < end; {
		if A[start] % 2 == 0 && A[end] % 2 == 0 {
			start += 1
		} else if A[start] % 2 == 0 && A[end] % 2 != 0 {
			end -= 1
			start += 1
		} else if A[start] %2 != 0 && A[end] % 2 == 0 {
			A[start], A[end] = A[end], A[start]
			start += 1
			end -= 1
		} else {
			end -= 1
		}
	}
	return A
}
```