### 解题思路
遍历两个链表,求和并保存进位.每次循环构造一个新节点到结果链表尾部

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
	head := &ListNode{}
	p := head
	carry := 0
	for l1 != nil || l2 != nil {
		s := carry
		if l1 != nil {
			s += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			s += l2.Val
			l2 = l2.Next
		}
		carry = 0
		if s >= 10 {
			s -= 10
			carry = 1
		}
		p.Next = &ListNode{
			Val:  s,
			Next: nil,
		}
		p = p.Next
	}
    if carry >0 {
		p.Next = &ListNode{
			Val:  carry,
			Next: nil,
		}
	}
	return head.Next
}


```