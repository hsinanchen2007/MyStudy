```
func convertToBase7(num int) string {
	var result bytes.Buffer
	if num < 0 {
		result.WriteString("-")
		num = -1 * num
	}
	var res []string
	for {
		res = append(res, strconv.Itoa(num%7))

		if num/7 == 0 {
			break
		}
		num = num / 7
	}

	for i := range res {
		result.WriteString(res[len(res)-1-i])
	}
	return result.String()
}
```