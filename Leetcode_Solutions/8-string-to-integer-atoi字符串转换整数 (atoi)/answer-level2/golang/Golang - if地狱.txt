
```go
func myAtoi(str string) int {
	var (
		max = 1 << 31 - 1
		min = -1 << 31
		hasStarted = false // 已开始
		isRealNumber = false // 排除0为首
		retString string
		ret int = 0
	)
	//retBytes :=
	for _, v := range str {
		switch v {
		case '-':
			if hasStarted {
                if isRealNumber {
                    goto end
                } else {
                    return 0  
                }
			} else {
				retString += "-"
				hasStarted = true
			}
		case '0':
			if isRealNumber {
				retString += "0"
			} else {
				hasStarted = true
			}
		case '1', '2', '3', '4', '5', '6', '7', '8', '9':
			retString += string(v)
			isRealNumber = true
			hasStarted = true
		default:
			if hasStarted {
				// 已开始就打断
				goto end
			} else {
				if v == '+' {
					hasStarted = true
				} else if v != ' ' {
					return 0
				}
			}
		}
	}
	// 结束
	end:
		for i, level := len(retString) - 1, 1; i >= 0; i, level = i - 1, level * 10 {
			switch v := retString[i]; {
			case v >= 48 && v <= 57:
				ret += level * (int(v) - 48)
                if ret > max || level > 1000000000 {
                    if retString[0] == '-' {
                        return min
                    } else {
                        return max
                    }
                }
			case v == '-':
				ret = -ret
			}
		}

		if ret > max {
			return max
		} else if ret < min {
			return min
		} else {
			return ret
		}
}
```
