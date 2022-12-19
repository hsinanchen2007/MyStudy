
```
func calculate(s string) int {
        ss := strings.Replace(s, " ", "", -1) //字符串去空
	str := strings.SplitAfter(ss, "")     //转数组
	stack := make([]int, 0)
	c := "+"
	num := 0
	for i := 0; i <= len(str); i++ {
		if isDigit(str, i) {
			tmp, _ := strconv.Atoi(str[i])
			num = num*10 + tmp
		} else {
			switch c {
			case "+":
				stack = append(stack, num)
				break
			case "-":
				stack = append(stack, -num)
				break
			case "*":
				num *= stack[len(stack)-1]
				stack = stack[:len(stack)-1]
				stack = append(stack, num)
				break
			case "/":
				num = stack[len(stack)-1] / num
				stack = stack[:len(stack)-1]
				stack = append(stack, num)
				break
			}
			num = 0
			if i < len(str) {
				c = str[i]
			}

		}
	}
	res := 0
	for i := 0; i < len(stack); i++ {
		res += stack[i]
	}
	return res
}

func isDigit(s []string, i int) bool {    //判断是否为数字
	if i >= len(s) {
		return false
	}
	_, err := strconv.Atoi(s[i])
	return err == nil
}
```


