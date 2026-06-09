### 解题思路
使用两个栈,存储链表的值.再构造新链表.

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	stack1, stack2 := make([]int, 0), make([]int, 0)
	p := l1
	for p != nil {
		stack1 = append(stack1, p.Val)
		p = p.Next
	}
	p = l2
	for p != nil {
		stack2 = append(stack2, p.Val)
		p = p.Next
	}
	n1, n2 := len(stack1)-1, len(stack2)-1
	p = nil
	carry := 0
	for n1 >= 0&& n2 >= 0 {
		val := stack1[n1] + stack2[n2] + carry
		carry = 0
		if val > 9 {
			val -= 10
			carry = 1
		}
		n1--
		n2--
		node := &ListNode{
			Val:  val,
			Next: p,
		}
		p = node
	}
	for n1 >= 0{
		val := stack1[n1] + carry
		carry = 0
		if val > 9 {
			val -= 10
			carry = 1
		}
		n1--
		node := &ListNode{
			Val:  val,
			Next: p,
		}
		p = node
	}
	for n2 >= 0{
		val := stack2[n2] + carry
		carry = 0
		if val > 9 {
			val -= 10
			carry = 1
		}
		n2--
		node := &ListNode{
			Val:  val,
			Next: p,
		}
		p = node
	}
	if carry > 0 {
		node := &ListNode{
			Val:  carry,
			Next: p,
		}
		p = node
	}
	return p
}
```