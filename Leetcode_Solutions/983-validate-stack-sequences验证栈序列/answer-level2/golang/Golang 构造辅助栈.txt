1. 主循环：poped中的每一个元素， 和**栈顶的元素**对比，
2.  相等就出栈，继续下一个poped元素               此分支结束条件：poped循环完毕，证明是正确的出栈顺序，返回true
3.  栈为空或者不相等，将pushed中的元素入栈          此分支结束条件：pushed中的元素全部入栈完毕，栈顶和poped的元素仍不相等，返回false

```
func validateStackSequences(pushed []int, popped []int) bool {
	// 主循环：pop中的每一个元素， 和栈顶的元素对比，
	// 相等就出栈，继续下一个pop元素  -- pop循环完毕 返回true
	// 不相等或者栈为空，就继续入栈   --结束条件：pushed已经全部入栈，pop还未循环完毕
	//
	stack := make([]int,0,len(pushed))
	pushIdx := 0
	for i := 0; i < len(popped);{
		if len(stack) == 0 || popped[i] != stack[len(stack)-1] {
			if pushIdx == len(pushed) {
				return false
			}
			stack = append(stack, pushed[pushIdx])
			pushIdx++
		} else {
			stack = stack[:len(stack)-1]
			i++
		}
	}
	return true
}
```
