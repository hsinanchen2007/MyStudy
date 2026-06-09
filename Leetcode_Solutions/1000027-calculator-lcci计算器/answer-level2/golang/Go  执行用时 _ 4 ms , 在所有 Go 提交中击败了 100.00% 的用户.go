### 解题思路
注意细节 for 依次计算，

### 代码

```golang

func calculate(s string) int {
	var stack []int
	// op num 表示上一个操作符或者数字
	var num int
	var op byte = '+'
	l := len(s)
	for i := 0; i <= l; i++ {
		v, ok := isDigit(s, i)
		// 如果是数字就循环计算
		if ok {
			num = num*10 + v
			// 跳过空格
		} else if i < len(s) && s[i] == ' ' {
			continue
		} else {

			//  只有加减乘除，没有括号，加减比乘除优先级低
			switch op {
			case '+':
				stack = append(stack, num)
			case '-':
				stack = append(stack, -num)
			case '*':
				// pop
				stackv := stack[len(stack)-1]
				stack = stack[:len(stack)-1]

				newnum := num * stackv
				stack = append(stack, newnum)

			case '/':
				// pop
				stackv := stack[len(stack)-1]
				stack = stack[:len(stack)-1]

				newnum := stackv / num
				stack = append(stack, newnum)
			}
			num = 0
			if i < len(s) {
				op = s[i]
			}
		}
	}
	res := 0
	for i := 0; i < len(stack); i++ {
		res += stack[i]
	}

	return res
}
func isDigit(s string, i int) (int, bool) {
	if i > len(s)-1 {
		return -1, false
	}
	if s[i]-'0' >= 0 && s[i]-'0' <= 9 {
		return int(s[i] - '0'), true
	}
	return -1, false
}

```