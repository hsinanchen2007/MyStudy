### 解题思路

1. 先去掉空格
2. 对第一个字符进行判断出-,+字符，并进行标记。
3. 过滤掉非数字的字符
4. 字符转化为数字

### 代码

```golang
func myAtoi(str string) int {
    // 去掉前后空格
	str = strings.TrimSpace(str)
	if len(str) == 0 {
		return 0
	}
	var (
		sign int // 标记是正还是负，正为1， 负为-1
		abs string// 填充绝对值的数字变量
		absNumber int // 转化为数字的结果变量
	)
	// 对第一个字符进行判断分析。包括-，+，0-9，其它字符的判断
	switch str[0] {
	case '-':
		sign, abs = -1, str[1:]
	case '+':
		sign, abs = 1, str[1:]
	default:
		sign, abs = 1, str // 里面还可能存在其它字符
	}
	// 过滤掉非数字的字符
	for i, s := range abs {
		if s < '0' || s > '9' { // 只要遇到不是数字的字符，后面的就放弃掉。
			abs = abs[:i]
			break
		}
	}
	// 字符转化为数字的过程
	for _, num := range abs {
		// b - '0' ==> 得到这个字符类型的数字的真实数值的绝对值
		absNumber = absNumber * 10 + int(num - '0')
		switch {
		case sign == -1 && sign *absNumber < -1<<31:// 为负数时，判断是否超出int32位最小值
			return -1<<31
		case sign == 1 && absNumber > 1<<31-1:// 为正数时，判断是否超出int32最大值
			return 1<<31-1
		}
	}
	return absNumber*sign
}
```