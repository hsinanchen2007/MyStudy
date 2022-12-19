### 思路：
根据题意我们可以知道，一个运算符一定会跟随一对括号，比如 $(t)$。
所以我们可以直接判断 `expression[0]`，得到最外层的运算符，根据运算符处理内层的表达式。
* 如果不是运算符，肯定就是 `t` 或者 `f` 直接判断即可
* 如果是 $!$，里面要么就是单一的字符，要么就是一个新的表达式。再调用 parseBoolExpr 解析并取反即可。
* 如果是 $&$ 或者 $|$， 需要对里面每个表达式分别求解。通过括号匹配，拿到第一个 `(` 匹配的 `)` 里面的表达式，再通过 parseBoolExpr 计算出值。
* 在计算 $&$ 的时候，如果有一个值为 `false`，可以提前结束计算。同理，在计算 $|$ 时， 如果有一个值为 `true`，也可以提前结束计算。

完整代码见下：

```Go
func parseBoolExpr(expression string) bool {
	start, end := 2, len(expression)-1
	switch expression[0] {
	case '!':
		return Not(expression[start:end])
	case '&':
		return AndOr(expression[start:end], true)
	case '|':
		return AndOr(expression[start:end], false)
	default:
		return expression == "t"
	}
}

// flag &: true |: false
func AndOr(exp string, flag bool) bool {
	pre, idx := 0, 0
	for i := 0; i < len(exp); i++ {
		if exp[i] == '(' {
			if pre == 0 {
				idx = i
			}
			pre++
		} else if exp[i] == ')' {
			pre--
			if pre == 0 {
				t := parseBoolExpr(exp[idx-1 : i+1])
				if !t && flag {
					return false
				}
				if t && !flag {
					return true
				}
			}
		} else {
            if pre <= 0 {
				if exp[i] == 'f' && flag {
					return false
				}
				if exp[i] == 't' && !flag {
					return true
				}
			}
		}
	}
	return flag
}

func Not(exp string) bool {
	if len(exp) == 1 {
		return !(exp == "t")
	}
	return !parseBoolExpr(exp)
}
```