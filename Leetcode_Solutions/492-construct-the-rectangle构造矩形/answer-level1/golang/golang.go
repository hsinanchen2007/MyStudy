```
func constructRectangle(area int) []int {
    var result []int
	if area == 0 {
		return []int{0, 0}
	}
	min := 1<<31 - 1

	for i := 1; i <= area; i++ {
		if float64(i) > math.Pow(float64(area), 0.5) {
			return result
		}

		if area%i != 0 {
			continue
		}

		j := area / i
		if (j-i) < min {
			result = []int{j, i}
			min = j - i
		}

	}
    return result
}
```