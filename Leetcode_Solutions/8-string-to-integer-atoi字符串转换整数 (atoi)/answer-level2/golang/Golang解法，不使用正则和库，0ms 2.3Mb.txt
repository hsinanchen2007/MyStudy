### 解题思路
实现思路参考了官方库，大致分两步走
1. 根据题意去除左侧的空格，并获取该数字的符号
2. 计算数值，逐个字符计算，并检查越界问题，以防超长字符串的无效计算

### 代码

```golang
const (
	intMax = int(^uint32(0) >> 1)
)

func myAtoi(s string) int {

    // trim space and get signal of the number
	nega := false
	for i := 0; i < len(s); i++ {
		if s[i] != ' ' {
			if nega = s[i] == '-'; nega || s[i] == '+' {
				i++
			}
			s = s[i:]
			break
		}
	}

	// compute the value
	var result int
	for _, ch := range []byte(s) {
		ch -= '0'
		if ch > 9 {
			break
		}
		result = result*10 + int(ch)
		if result > intMax {
			result = intMax
			if nega {
				result = ^result
			}
			return result
		}
	}
	if nega {
		result = - result
	}
	return result
}
```