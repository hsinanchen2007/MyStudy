## 结果

![image.png](https://pic.leetcode-cn.com/b058b390c9189ed8f6e2dd4a7c597512eb50ac2862965be964255b87c0f0bc91-image.png)

## 思路

用栈来存储数字

- 遍历tokens
    - 入到数字就入栈
    - 遇到一个运算符，弹出栈中的两个元素进行对应计算，然后再把结果压入栈中
- 最后栈中剩下的数就是最后答案

## Code
```golang
func evalRPN(tokens []string) int {
	stack := list.New()
	for _, s := range tokens {
		switch s {
		case "+":
			a := stack.Remove(stack.Front()).(int)
			b := stack.Remove(stack.Front()).(int)
			stack.PushFront(a + b)
		case "-":
			a := stack.Remove(stack.Front()).(int)
			b := stack.Remove(stack.Front()).(int)
            // 注意顺序 b - a
			stack.PushFront(b - a)
		case "*":
			a := stack.Remove(stack.Front()).(int)
			b := stack.Remove(stack.Front()).(int)
			stack.PushFront(a * b)
		case "/":
			a := stack.Remove(stack.Front()).(int)
			b := stack.Remove(stack.Front()).(int)
            // 注意顺序 b / a
			stack.PushFront(b / a)
		default:
			num, _ := strconv.Atoi(s)
			stack.PushFront(num)
		}
	}
	return stack.Remove(stack.Front()).(int)
}

```

