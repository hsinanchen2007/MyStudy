### 解题思路
单调递减栈

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nextLargerNodes(head *ListNode) []int {
	type node struct {
		index int
		val   int
	}
	n := 0
	p := head
	for p != nil {
		p = p.Next
		n++
	}
	nextLarger := make([]int, n)
	stack := make([]*node, 0, n)
	p = head
	for i := 0; i < n; i++ {
		for len(stack) > 0 && stack[len(stack)-1].val < p.Val {
			l := len(stack) - 1
			nextLarger[stack[l].index] = p.Val
			stack = stack[:l]
		}
		stack = append(
			stack,
			&node{
				index: i,
				val:   p.Val,
			},
		)
        p = p.Next
	}
	return nextLarger
}
```