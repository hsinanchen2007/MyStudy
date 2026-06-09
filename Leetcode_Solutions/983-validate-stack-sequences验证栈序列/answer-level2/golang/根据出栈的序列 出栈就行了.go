### 解题思路
元素不断的入栈 
我们按照给定的 出栈序列出栈  （如果能出完）就是一个出栈序列


已经出栈的元素 用-1标记 

【有用点个赞】让我知道
### 代码

```golang
func validateStackSequences(ru []int, chu []int) bool {

	ji := 0
	id := 0
	for i := 0; i < len(ru); i++ {

		for i>=0&&id<len(chu)&&ru[i] == chu[id] {
			ru[i] = -1
			ji++

			id++
			for i>=0&&ru[i]==-1{
			i--}
		}
	}

	return ji == len(ru)

}
```