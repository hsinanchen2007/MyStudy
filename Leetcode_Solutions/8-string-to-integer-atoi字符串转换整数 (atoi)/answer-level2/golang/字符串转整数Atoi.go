### 解题思路
1.首先把左边的空格去掉。
2.判断是否是-或者+开头，去除开头+-符号，并确定是正数还是负数
3.从头开始验证字符是否在'0' <= c <= '9'之间
4.判断是否越界
4.1 如果是正数，10*n + int(c - '0') > math.MaxInt 也就是10*n < math.MaxInt - int(c - '0')
4.2 如果是负数 10*n + int(c - '0') > math.MaxInt + 1 也就是10*n - 1 > math.MaxInt - int(c - '0')
### 代码

```golang
func myAtoi(s string) int {
	s = trimLeft(s)
	if len(s) == 0 {
		return 0
	}

	s0 := s
	if s0[0] == '+' || s0[0] == '-' {
		s = s[1:]
	}

	if len(s) == 0 {
		return 0
	}
	neg := s0[0] == '-' // 是否为负数
	n := 0
	for _, c := range []byte(s) {
		if '0' <= c && c <= '9' {
			// 如果是正数
			if !neg && n*10 > math.MaxInt32 - int(c - '0') {
				return math.MaxInt32
			}
			// 如果是负数
			if neg && n*10 - 1 > math.MaxInt32 - int(c - '0') {
				return math.MinInt32
			}
			n = 10*n + int(c - '0')
		} else {
			break
		}
	}
	if s0[0] == '-' {
		return 0 - n
	}
	return n
}

// 去除开头空格
func trimLeft(s string) string {
	s0 := s
	for i, c := range []byte(s0) {
		if c == ' ' {
			s = s0[i+1:]
		} else {
			break
		}
	}
	return s
}
```