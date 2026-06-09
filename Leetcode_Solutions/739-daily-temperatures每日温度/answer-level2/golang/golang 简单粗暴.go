```
// 防止重复遍历，在遍历数组每个元素的时候记录当前的位置
type node struct {
    val int
    pos int
}

func dailyTemperatures(T []int) []int {
	res := make([]int, len(T), len(T))
	stack := make([]node, 0, len(T))
	for i, t := range T {
        node := node{t, i}
		for len(stack) > 0 && stack[len(stack)-1].val < t {
			res[stack[len(stack)-1].pos] = i - stack[len(stack)-1].pos
        	stack = stack[:len(stack)-1]
		}
		stack = append(stack, node)
	}
	return res
}
```
