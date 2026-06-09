func encode(num int) string {
	if num == 0 {
		return ""
	}
	n := int(math.Log2(float64(num + 1)))
	sb := make([]byte, n)
	for i := 0; i < len(sb); i++ {
		sb[i] = '0'
	}

	L := len(sb)
	for i := L; i > 0; i-- {
		v := getValue(i)
		if num == v {
			sb[L-i] = '1'
			return string(sb)
		} else if num < v {
			sb[L-i] = '0'
			num -= int(math.Pow(float64(2), float64(i-1)))
		} else if num > v {
			sb[L-i] = '1'
			num -= int(math.Pow(float64(2), float64(i)))
		}
	}

	return string(sb)
}

func getValue(n int) int {
	v := int(math.Pow(float64(2), float64(n)))
	for i := n - 1; i > 0; i-- {
		v += int(math.Pow(float64(2), float64(i-1)))
	}
	return v
}