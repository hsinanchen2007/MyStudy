```
func addBinary(a string, b string) string {
	for len(a) < len(b) {
		a = "0" + a
	}
	for len(a) > len(b) {
		b = "0" + b
	}
	arrA := append([]string{"0"}, strings.Split(a, "")...)
	arrB := append([]string{"0"}, strings.Split(b, "")...)
	for i := len(arrA)-1; i > 0; i-- {
		switch arrA[i] + arrB[i] {
		case "00":
			arrA[i] = "0"
		case "01", "10", "010":
			arrA[i] = "1"
		case "11", "011", "110":
			arrA[i] = "0"
			arrA[i-1] += "1"
		case "111":
			arrA[i] = "1"
			arrA[i-1] += "1"
		}
	}
	if arrA[0] == "0" {
		arrA = arrA[1:]
	} else if arrA[0] == "01" {
		arrA[0] = "1"
	}
	var c strings.Builder
	for _, v := range arrA {
		c.WriteString(v)
	}
	return c.String()
}
```
