用栈理解起来好理解，题解不唯一，只需要输出一个，被示例二困了好一会

```
func maxDepthAfterSplit(seq string) []int {
	stack := make([]int, 0, len(seq))
	var deep = -1
	for _, v := range seq {
		if string(v) == "(" {
			deep++
			stack = append(stack, deep%2)
		}
		if string(v) == ")" {
			stack = append(stack, deep%2)
			deep--
		}
	}
	return stack
}
```
