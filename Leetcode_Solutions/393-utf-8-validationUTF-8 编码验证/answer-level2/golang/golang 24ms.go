```
func validUtf8(data []int) bool {
	if len(data) == 0 {
		return false
	}
	count := 0
	for i := 0; i < len(data); i++ {
		if count == 0 {
			count = getCount(data[i])
		} else {
			if data[i] & (1 << 7) == 0 {
				return false
			}
			count--
		}

		if count == -1 {
			return false
		}
	}
	return count == 0
}

func getCount(n int) int {
	v := fmt.Sprintf("%08b", n)
	if v[0] == '0' {
		return 0
	}
	if v[:2] == "10" {
		return -1
	}
	if v[:3] == "110" {
		return 1
	}
	if v[:4] == "1110" {
		return 2
	}
	if v[:5] == "11110" {
		return 3
	}
	return -1
}

```
