### 解题思路
此处撰写解题思路

### 代码

```golang
func myAtoi(str string) int {
	new_str := ""
	// 去掉空格字符
	for i := 0; i < len(str); i++ {
		if str[i] != ' ' {
			new_str = str[i:]
			break
		}
	}
	if len(new_str) == 0 {
		return 0
	}
	// 纪录正负号
	pg := ""
	if new_str[0] == '+' || new_str[0] == '-' {
		pg = string(new_str[0])
		new_str = new_str[1:]
	} else if new_str[0] < '0' && new_str[0] > '9' {
		return 0
	}

	new_new_str := ""
	// 截取数字
	for i := 0; i < len(new_str); i++ {
		if new_str[i] >= '0' && new_str[i] <= '9' {
			new_new_str += string(new_str[i])
		} else {
			break
		}
	}
	if len(new_new_str) == 0 {
		return 0
	}

	var data int64 = 0
	var sign int64 = 1

	if pg == "-" {
		sign = -1
	}
	// 纯数字
	for i := 0; i < len(new_new_str); i++ {
		if sign*(data*10+int64(new_new_str[i]-'0')) > math.MaxInt32 {
			return math.MaxInt32
		}
		if sign*(data*10+int64(new_new_str[i]-'0')) < math.MinInt32 {
			return math.MinInt32
		}

		data = data*10 + int64(new_new_str[i]-'0')
	}

	data = sign * data
	if data >= math.MinInt32 && data <= math.MaxInt32 {
		return int(data)
	} else if data > math.MaxInt32 {
		return math.MaxInt32
	} else {
		return math.MinInt32
	}
}

```