思路：
假设现在左侧k个全是左括号，接下来分别是两块匹配的括号区域，((..【区域1】【区域2】
则当走到区域2末尾时，因为区域1结束时和区域2结束时其未匹配的括号数目一致，所以他们应该合并起来
而如果区域1和区域2中有不匹配的括号，如((..【区域1】(【区域2】，那么在区域2处理完毕时，这俩还不能合并起来
我们将匹配区域1、2整体抽象为（区域的左右括号数目，其左侧的未匹配左括号数目），并将处理到当前为止每个未匹配的左括号抽象为（0，其左侧的未匹配左括号数目+1（自身））
所以我们有以下思路，
在每次遇到左括号的时候，在主堆栈中压入左括号，在辅助堆栈中压入（0，栈顶元素的左侧未匹配的左括号数目+1）
当遇到右括号时，若主堆栈为空，则重置辅助堆栈；否则我们从辅助堆栈中取出栈顶元素，将其匹配括号数+2，然后由于其未匹配左括号数与新的栈顶元素是一致的,我们可以将其叠加到该元素上，然后判断是否需要更新最大匹配数

代码如下
```Go
type Ele struct {
	CurLen       int
	UnpairedLeft int
}

func longestValidParentheses(s string) int {
	maxLen := 0

	// 主堆栈，用于判断至此为止的括号的匹配情况，以及判断是否完全不可能匹配了
	var stack []byte
	// 辅助堆栈，用于合并不同的括号区域
	var eleStack []Ele = []Ele{{0, 0}}
	for _, char := range []byte(s) {
		lastEle := eleStack[len(eleStack)-1]
		if char == '(' {
			// (
			stack = append(stack, char)
			eleStack = append(eleStack, Ele{CurLen: 0, UnpairedLeft: lastEle.UnpairedLeft + 1})
		} else {
			// )
			if len(stack) == 0 {
				eleStack = []Ele{{0, 0}}
				continue
			}

			stack = stack[:len(stack)-1]
			// 将原栈顶加上本次两个括号后，然后与新栈顶叠加
			eleStack = eleStack[:len(eleStack)-1]
			eleStack[len(eleStack)-1].CurLen += lastEle.CurLen + 2

			if eleStack[len(eleStack)-1].CurLen > maxLen {
				maxLen = eleStack[len(eleStack)-1].CurLen
			}
		}
	}

	return maxLen
}

```
