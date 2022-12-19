### 解题思路
学习[@z1m](/u/z1m/)大佬
[大佬详细讲解传送门](https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/solution/tan-xin-by-z1m/)

### 知识点：贪心思想 + 辅助栈

### 代码
```golang
func validateStackSequences(pushed []int, popped []int) bool {
	stack := make([]int,0)	//	辅助栈
	//	按照pushed顺序将元素压入stack中
	//	贪心思想：如果此时stack栈顶的元素==popped序列中下一个出现的值，则将该值立刻从stack中pop出来
	j := 0	//	遍历popped的"指针"
	for _, value := range pushed {
		stack = append(stack, value)
		for len(stack) != 0 && stack[len(stack)-1] == popped[j] {
			stack = stack[:len(stack)-1]	//	左闭右开
			j++
		}
	}

	//	最后，若栈空，则满足顺序，返回true，否则，返回false
	if len(stack) == 0 {
		return true
	} else {
		return false
	}
}

// 主函数
func main() {
	pushed := []int{1, 2, 3, 4, 5}
	popped := []int{4, 5, 3, 2, 1}
	fmt.Println(validateStackSequences(pushed, popped))
}
```