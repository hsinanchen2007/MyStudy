### 解题思路
判断空格、符号、数值，遇到其他字符直接break，不算难。

### 代码

```golang
func myAtoi(str string) (result int) {
	min := - int(math.Pow(2, 31))
	max :=  int(math.Pow(2, 31)) - 1
	ns := getNumStr(str)
	result, _ = strconv.Atoi(ns)
	if result > max {
		return max
	}
	if result < min {
		return min
	}
	return
}

func getNumStr(str string) (result string) {
	isBlank := true
	isSymble := true
	for _, v := range str {
		if v == ' ' && isBlank {
			continue
		} else if result == "" && isSymble && (v == '+' || v == '-') {
			result += string(v)
			isSymble = false
			isBlank = false
		} else if !isNum(v) {
			break
		} else if isNum(v) {
			result += string(v)
			isBlank = false
		} else {
			isBlank = false
		}
	}
	if result == "" || result == "+" || result == "-" {
		return "0"
	}
	return
}

func isNum(n rune) bool {
	if n == '0' || n == '1' || n == '2' || n == '3' || n == '4' || n == '5' || n == '6' || n == '7' || n == '8' || n == '9' {
		return true
	} else {
		return false
	}
}
```