### 解题思路
单调递增栈

### 代码

```golang
func removeKdigits(num string, k int) string {
	if k <= 0 {
		return num
	}
	runes := make([]rune, 0, len(num))
	i := 0

	for _, c := range num {
		i++
		for len(runes) > 0 && c < runes[len(runes)-1] {
			runes = runes[0 : len(runes)-1]
			k--
			if k == 0 {
				break
			}
		}
		runes = append(runes, c)
		if k == 0 {
			break
		}
	}
	if k > 0 {
		runes = runes[0:len(runes)-k]
	}
	for len(runes) > 0 && runes[0] == '0' {
		runes = runes[1:]
	}
	
	result := string(runes) + num[i:]
	if result == "" {
		return "0"
	}
	return result
}

```