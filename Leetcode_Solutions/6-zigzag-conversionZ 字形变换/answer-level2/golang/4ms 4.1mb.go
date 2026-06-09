````
func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	var result strings.Builder
	step := 2 * numRows - 2

	for i := 0; i < numRows; i++ {
		for j, temp, add := i, 0, 0; j < len(s); temp++ {
			result.WriteByte(s[j])
			if i == 0 || i == numRows - 1 {
				add = step
			} else if temp % 2 == 0 {
				add = step - 2 * i
			} else {
				add = 2 * i
			}
			j += add
		}
	}
	return result.String()
}
````