### 解题思路
比较简单,利用栈的思想,遍历输入的数组,依次入栈,遇到运算符就出栈两个元素(第一个出栈元素放运算符右边)进行运算,并将结果入栈
最后栈里只会剩下计算结果

### 代码

```golang
func evalRPN(tokens []string) int {
    number := []int{}
	for _, val := range tokens{
		l := len(number)
		switch val {
		case "+":
			number  = append(number[:l -2], number[l-2] + number[l-1])
		case "-":
			number  = append(number[:l -2], number[l-2] - number[l-1])
		case "*":
			number  = append(number[:l -2], number[l-2] * number[l-1])
		case "/":
			number  = append(number[:l -2], number[l-2] / number[l-1])
		default:
			num, _ := strconv.Atoi(val)
			number  = append(number, num)
		}
	}
	return number[0]
}
```