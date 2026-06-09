```
func canMakePaliQueries(s string, queries [][]int) []bool {
	bitValues := make([]int, len(s))
	ans := make([]bool, len(queries))
	ss := []byte(s)
	for i, c := range ss {
		if i == 0 {
			bitValues[i] = 1 << (c - 'a')
		} else {
			bitValues[i] = bitValues[i-1] ^ (1 << (c - 'a'))
		}
	}
	for i, query := range queries {
		left := query[0]
		right := query[1]
		leftBitValue := 0
		if left > 0 {
			leftBitValue = bitValues[left-1]
		}
		rightBitValue := bitValues[right]
		bitValue := leftBitValue ^ rightBitValue
		k := query[2]
		count := 0
		for bitValue != 0 {
			if (bitValue & 1) == 1 {
				count++
			}
			bitValue = bitValue >> 1
		}
		ans[i] = 2 * k >= (count - 1)
	}
	return ans
}
```
