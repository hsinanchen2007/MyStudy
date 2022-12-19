```
func hammingDistance(x int, y int) int {
    result := 0
	z := x ^ y
	for {
		if z%2 == 1 {
			result++
		}
		z = z >> 1
		if z == 0 {
			break
		}
	}

	return result
}
```