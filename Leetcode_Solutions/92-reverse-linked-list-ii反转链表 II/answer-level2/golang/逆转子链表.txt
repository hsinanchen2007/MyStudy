### 解题思路
找到第m个节点，以此节点开头，翻转n-m个节点，同时衔接首尾

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	p := &ListNode{}
	p.Next = head
	h := p
	node := head
	for node != nil {
		if m == 1 {
			// 衔接首部
			p.Next = reverseSubList(node, n-m)
            break
		}
		m--
		n--
		p = node
		node = node.Next
	}
	return h.Next 
}

func reverseSubList(p *ListNode, count int) *ListNode {
	var prev *ListNode = nil
	var next *ListNode = nil
	var curr *ListNode = p
	for count >= 0{
		count--
		next = curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}
	// 衔接尾部
	p.Next = curr
	return prev
}

```