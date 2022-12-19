```
for i, a := range A {
		if i%2 == a%2 {
			continue
		}

		for j := i + 1; j < len(A); j++ {
			if A[j]%2 != a%2 {
				A[j], A[i] = A[i], A[j]
				break
			}
		}
	}

	return A
```