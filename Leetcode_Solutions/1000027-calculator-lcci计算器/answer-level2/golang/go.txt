### 解题思路
转成后缀表达式，用栈解

### 代码

```golang
func calculate(s string) int {
	prn := getPrn(s)
	v1, v2, val := 0, 0, 0
	var stack []int
	for i:=0; i<len(prn); i++ {
		str := prn[i]
		if len(stack) >= 2 {
			v1, v2 = stack[len(stack)-2],  stack[len(stack)-1]
		}
		switch str {
		    case  "+":
		    	val = v1 + v2
		    	stack = stack[:len(stack)-2]
		    	stack = append(stack, val)
			case "-":
				val = v1 - v2
				stack = stack[:len(stack)-2]
				stack = append(stack, val)
			case "*":
				val = v1 * v2
				stack = stack[:len(stack)-2]
				stack = append(stack, val)
			case "/":
				val = v1 / v2
				stack = stack[:len(stack)-2]
				stack = append(stack, val)
			default:
		        val, _ = strconv.Atoi(str)
			    stack = append(stack, val)
		}
	}
	if len(stack) != 1 {
		// fmt.Println("Error ", stack)
		return 0
	}else {
		return stack[0]
	}
}

func getPrn(s string) (prn []string) {
	in := strings.ReplaceAll(s, " ", "")
	var op []string
	val := ""
	for i:=0; i<len(in); i++ {
		c := string(in[i])
		switch c {
		case "*", "/":
			prn = append(prn, val)
			val = ""
			for len(op) > 0 && (op[len(op)-1] == "*" || op[len(op)-1] == "/") {
				prn = append(prn, op[len(op)-1])
				op = op[:len(op)-1]
			}
			op = append(op, c)
		case "+", "-":
			prn = append(prn, val)
			val = ""
			for len(op) > 0  {
				prn = append(prn, op[len(op)-1])
				op = op[:len(op)-1]
			}
			op = append(op, c)
		default:
			val += c
		}
	}
	if val != "" {
		prn = append(prn, val)
	}
	for len(op) > 0 {
		prn = append(prn, op[len(op)-1])
		op = op[:len(op)-1]
	}
	return prn
}
```