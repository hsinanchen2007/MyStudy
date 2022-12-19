仔细观察Lisp表达式的特点可以发现它完全是由单操作符运算递归嵌套构成的，每一层（指被一对括号框起来的部分）都只有一个操作符，完成单一的运算操作，不存在常规表达式那种 a+b+c 这样的多段运算，当然也不涉及什么运算优先级的问题。事实上如果没有let，只包含add和multi，题目会变得非常简单，只要一个实现了 a+b 和 a*b 两种简单计算的函数自递归就能完成解答，而现在Lisp表达式看起来比较复杂完全是因为let这种特殊格式的操作混入了add和multi之间。
在确定使用递归函数来完成计算的前提下，单独观察let的生效范围规则，可以发现它实际就是编程中的局部变量生效范围规则：局部变量覆盖外层的同名变量，重复赋值时新值覆盖旧值。因此只需要用map保存变量值，在递归过程中进行值传递，确保递归内层对map的修改不影响到外层map即可符合Lisp表达式的变量生效规则。需要注意的是golang的map是引用传递，需要手动进行map的值拷贝。
```
func evaluate(expression string) int {
	var vars = make(map[string]int)
	var ret int
	var expr = []byte(expression)
	for len(expr) > 0 {
		expr, _ = trimBracket(expr)
		expr, ret = eval(expr, vars)
	}
	return ret
}

func eval(expr []byte, vars map[string]int) ([]byte ,int) {
	var ret int
	var ok bool
	var str string
	var op byte

	expr, op = readOp(expr)
	switch op {
	case 'l': //let
		// make a separate copy so inner value won't influence parent variables
		vars = copyMap(vars)
		//a series of variable-number pairs
		for !testLetEnd(expr) {
			expr, str = readVar(expr)
			num := 0
			if expr, ok = trimBracket(expr); ok { // must be '('
				expr, num = eval(expr, vars)
			} else {
				expr, num = readValue(expr, vars)
			}
			vars[str] = num
		}
		// the let result at the end
		if expr, ok = trimBracket(expr); ok { // must be '('
			expr, ret = eval(expr, vars)
		} else {
			expr, ret = readValue(expr, vars)
		}
	case 'a': //add
		var num1, num2 int
		if expr, ok = trimBracket(expr); ok { // must be '('
			expr, num1 = eval(expr, vars)
		} else {
			expr, num1 = readValue(expr, vars)
		}
		if expr, ok = trimBracket(expr); ok { // must be '('
			expr, num2 = eval(expr, vars)
		} else {
			expr, num2 = readValue(expr, vars)
		}
		ret = num1 + num2
	case 'm': //multi
		var num1, num2 int
		if expr, ok = trimBracket(expr); ok { // must be '('
			expr, num1 = eval(expr, vars)
		} else {
			expr, num1 = readValue(expr, vars)
		}
		if expr, ok = trimBracket(expr); ok { // must be '('
			expr, num2 = eval(expr, vars)
		} else {
			expr, num2 = readValue(expr, vars)
		}
		ret = num1 * num2
	}
	expr, _ = trimBracket(expr) // must be ')'
	return expr, ret
}

func testLetEnd(expr []byte) bool {
	if expr[0] == '(' { // only let return can be sub-expr
		return true
	}
	for i:=0; true; i++ {
		if expr[i] == ' ' {
			return false
		}
		if expr[i] == ')' {
			return true
		}
	}
	// meaningless, just for grammar check
	return false
}

func trimBracket(expr []byte) ([]byte, bool) {
	if expr[0] == '(' {
		return expr[1:], true
	}
	if expr[0] == ')' {
		if len(expr) > 1 && expr[1] == ' ' {
			return expr[2:], true
		} else {
			return expr[1:], true
		}
	}
	return expr, false
}

func readOp(expr []byte) ([]byte ,byte) {
	if isEqual(expr, "let") {
		return expr[4:], 'l'
	}
	if isEqual(expr, "add") {
		return expr[4:], 'a'
	}
	//if isEqual(expr, "mult") {
	return expr[5:], 'm'
	//}
}

func readNum(expr []byte) ([]byte, int) {
	length := 1
	for length<len(expr) && expr[length]>='0' && expr[length]<='9' {
		length++
	}
	num := 0
	start := 0
	if expr[0] == '-' {
		start = 1
	}
	for i := start; i < length; i++ {
		num = num * 10 + int(expr[i] - '0')
	}
	if expr[0] == '-' {
		num = -num
	}
	if expr[length] == ' ' {
		return expr[length+1:], num
	} else {
		return expr[length:], num
	}
}

func readVar(expr []byte) ([]byte, string) {
	length := 1
	for length<len(expr) && expr[length]!=' ' && expr[length]!=')' {
		length++
	}
	if expr[length] == ' ' {
		return expr[length+1:], string(expr[:length])
	} else {
		return expr[length:], string(expr[:length])
	}
}

func readValue(expr []byte, vars map[string]int) ([]byte, int) {
	if (expr[0] >= '0' && expr[0] <= '9') || expr[0] == '-' {
		return readNum(expr)
	} else {
		var str string
		expr, str = readVar(expr)
		return expr, vars[str]
	}
}

func isEqual(s1 []byte, s2 string) bool {
	if len(s1) < len(s2) {
		return false
	}
	for i:=0; i<len(s2); i++ {
		if s1[i] != s2[i] {
			return false
		}
	}
	return true
}

func copyMap(m map[string]int) map[string]int {
	var ret = make(map[string]int)
	for k, v := range m {
		ret[k] = v
	}
	return ret
}
```
