### 解题思路

重点各种逻辑


### 代码

```golang

const (
	// 32 位有符号整数最大值
	intMAX = 1<<31 - 1
	// 32 位有符号整数最小值
	intMIN = -1 << 31
)

func myAtoi(str string) int {
	str = strings.TrimSpace(str)
	ret := 0

	i := 0
	neg := false
	sz := len(str)
	if sz == 0 {
		return 0
	}
	if str[0] == '-' || str[0] == '+' {
		i = 1
		neg = isNeg(str[0])
	}

	for ; i < sz; i++ {
		if str[i] >= '0' && str[i] <= '9' {
			ret = ret*10 + int(str[i]-'0')
			if ret >= intMAX {
				break
			}
		} else {
			break
		}
	}

	
	if neg {
		if -ret < intMIN {
			return intMIN
		}
		return -ret
	}

	if ret > intMAX {
		return intMAX
	}
	return ret
}

func isNeg(a byte) bool {
	if a == '-' {
		return true
	}
	return false
}

```