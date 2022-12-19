```
import (
	"container/list"
	"strconv"
)

func evalRPN(tokens []string) int {
	var (
		i, num1, num2 int
		length        = len(tokens)
		stack         = list.New()
		e1, e2        *list.Element
	)
	if length == 0 {
		return 0
	}

	for i = 0; i < length; i++ {
		switch tokens[i] {
		case "+":
			fallthrough
		case "-":
			fallthrough
		case "*":
			fallthrough
		case "/":
			e1 = stack.Back()
			num1 = e1.Value.(int)
			stack.Remove(e1)
			e2 = stack.Back()
			num2 = e2.Value.(int)
			stack.Remove(e2)
			switch tokens[i] {
			case "+":
				stack.PushBack(num2 + num1)
			case "-":
				stack.PushBack(num2 - num1)
			case "*":
				stack.PushBack(num2 * num1)
			case "/":
				stack.PushBack(num2 / num1)
			}
		default:
			val, _ := strconv.Atoi(tokens[i])
			stack.PushBack(val)
		}
	}

	e1 = stack.Back()
	return e1.Value.(int)
}

```
