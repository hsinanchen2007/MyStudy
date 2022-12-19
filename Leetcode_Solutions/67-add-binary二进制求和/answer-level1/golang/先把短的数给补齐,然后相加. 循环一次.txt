先把短的数给补齐,然后相加. 循环一次
```
func addBinary(a string, b string) string {
	if a == "" && b == "" {
		return ""
	} else if a == "" && b != "" {
		return b
	} else if a != "" && b == "" {
		return a
	}
	lengthMax := len(a)
	lengthMin := len(b)
	if lengthMax < lengthMin {
		lengthMax, lengthMin = lengthMin, lengthMax
	}
	for len(a) < lengthMax {
		a = "0" + a
	}
	for len(b) < lengthMax {
		b = "0" + b
	}
	numA := []rune(a)
	numB := []rune(b)

	sum := make([]rune, lengthMax, lengthMax)
	carry := rune(0)
	for i := lengthMax - 1; i >= 0; i-- {
		s := carry + numA[i] + numB[i] - 96
		if s <= 1 {
			sum[i] = s
			carry = 0
		} else if s == 2 {
			sum[i] = 0
			carry = 1
		} else if s == 3 {
			sum[i] = 1
			carry = 1
		} else {
			fmt.Println("something wrong!")
		}
		sum[i] += 48
	}

	ret := string(sum)
	if carry == 1 {
		ret = "1" + ret
	}

	return ret
}
```