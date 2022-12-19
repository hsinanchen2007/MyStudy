### 解题思路
计数

### 代码

```golang
type Item struct {
	val rune
	cnt int
}

func removeDuplicates(s string, k int) string {
	stack := make([]Item, 0, len(s))
	for _, c := range s {
		if len(stack) == 0 || stack[len(stack)-1].val != c {
			stack = append(stack, Item{
				val: c,
				cnt: 1,
			})
		} else {
			stack[len(stack)-1].cnt++
		}
		for len(stack) > 0 {
			if stack[len(stack)-1].cnt == k {
				stack = stack[:len(stack)-1]
			} else {
				break
			}
		}
	}
	runes := make([]rune, 0, len(s))
	for _, item := range stack {
		for item.cnt > 0 {
			runes = append(runes, item.val)
			item.cnt--
		}
	}
	return string(runes)
}
```