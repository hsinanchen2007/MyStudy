```
func addBinary(a string, b string) string {
	var s string
	carry := 0 // 进位
	for i, j := len(a)-1, len(b)-1; i >= 0 || j >= 0; i, j = i-1, j-1 {
		tmp1, tmp2 := 0, 0
		if i >= 0 {
			tmp1 = int(a[i] - '0')
		}
		if j >= 0 {
			tmp2 = int(b[j] - '0')
		}
		sum := carry + tmp1 + tmp2
		if sum >= 2 {
			carry = 1
		} else {
			carry = 0
		}
		sum = sum % 2
		s = strconv.Itoa(sum) + s
	}
	if carry == 1 {
		s = "1" + s
	}
	return s
}
```
