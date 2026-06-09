### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	//迭代
	stack := make([]*ListNode, 0)
	p := head
	// 进栈
	for p != nil {
		stack = append(stack, p)
		p = p.Next
	}
    // fmt.Println(len(stack))
	// 出栈
	res := &ListNode{} //空节点
	p = res
	for len(stack) != 0 {
		p.Next = stack[len(stack)-1]
		p = p.Next
		stack = stack[:len(stack)-1]
	}
    // fmt.Println(len(stack))
    p.Next=nil
	return res.Next
}
```