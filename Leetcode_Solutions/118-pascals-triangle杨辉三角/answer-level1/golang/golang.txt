```
func generate(numRows int) [][]int {
	result := [][]int{}

	line1 := []int{1}
	line2 := []int{1, 1}

	if numRows == 0 {
		return result
	}

	if numRows >= 1 {
		result = append(result, line1)

	}

	if numRows >= 2 {
		result = append(result, line2)
	}

	if numRows >= 3 {
		for i := 2; i < numRows; i++ {
			result = append(result, generateNewLine(result[i-1]))
		}
	}

	return result
}

func generateNewLine(oldLine []int) (newLine []int) {
	oldLen := len(oldLine)

	newLine = append(newLine, 1)
	for i := 1; i < oldLen; i++ {
		newLine = append(newLine, oldLine[i]+oldLine[i-1])
	}
	newLine = append(newLine, 1)

	return newLine
}

```