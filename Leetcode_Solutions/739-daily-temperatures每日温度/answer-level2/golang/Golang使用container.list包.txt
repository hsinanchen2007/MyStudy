### 解题思路
典型单调栈的解法。

### 代码

```golang
func dailyTemperatures(T []int) []int {
    res := make([]int, len(T), len(T))
    stack := list.New()
    for i, num := range T {
		for stack.Len() != 0 && T[stack.Front().Value.(int)] < num {
			ind := stack.Remove(stack.Front()).(int)
			res[ind] = i-ind
		}
        stack.PushFront(i)
    }
    return res
}
```