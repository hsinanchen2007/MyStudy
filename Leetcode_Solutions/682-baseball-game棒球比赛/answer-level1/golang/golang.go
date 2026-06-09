```
func calPoints(ops []string) int {
    var result []int
	var sum int
	for _, op := range ops {
		switch op {
		case "C":
			if len(result) > 0 {
				result = result[:len(result)-1]
			}
		case "D":
			if len(result) > 0 {
				result = append(result, result[len(result)-1]*2)
			}
		case "+":
			if len(result) > 1 {
				result = append(result, result[len(result)-1]+result[len(result)-2])
			}
		default:
			score, _ := strconv.Atoi(op)
			result = append(result, score)
		}
	}

	for _, res := range result {
		sum += res
	}

	return sum
}
```