### 解题思路
# 首先想到就是用栈（后进先出）
  遍历数组，将当前最大的数压栈，判断栈顶与当前数大小，栈顶>curNum,栈顶出栈，然后将curNum压入栈
### 代码

```golang

type Stack struct {
	val   int
	index int
}
func dailyTemperatures(T []int) []int {
    //入栈
	tempStack := make([]Stack, 0)
	day := make([]int, len(T))
	p := 0
	for i, v := range T {
		p++
		for len(tempStack) > 0 {
			if v > tempStack[len(tempStack)-1].val {
				day[tempStack[len(tempStack)-1].index] = i - tempStack[len(tempStack)-1].index

				tempStack = tempStack[:len(tempStack)-1]
			} else {
				break
			}
		}
		tempStack = append(tempStack, Stack{v, i})

	}
	return day
}
```