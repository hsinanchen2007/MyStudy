```
func shortestToChar(S string, C byte) []int {
    result := []int{}

	for i := range S {
		if S[i] == C {
			result = append(result, 0)
			continue
		}

		min := len(S)

		for j := i + 1; j < len(S); j++ {
			if S[j] == C {
				if (j - i) < min {
					min = j - i
				}
				break
			}
		}

		for j := i - 1; j >= 0; j-- {
			if S[j] == C {
				if (i - j) < min {
					min = i - j
				}
				break
			}
		}

		result = append(result, min)
	}

	return result
}
```