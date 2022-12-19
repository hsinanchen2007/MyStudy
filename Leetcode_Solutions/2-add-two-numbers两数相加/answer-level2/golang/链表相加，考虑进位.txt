### 解题思路
两个链表依次相加，保留进位，相加直至任何一个链表为空且进位为0
可以复用输入的节点，避免不必要的内存分配

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
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	node1 := l1
	node2 := l2
	var c int
	var headNode *ListNode // not nil
	var prevNode *ListNode
	for {
		if c == 0 {
			if node1 == nil && node2 == nil {
				break
			}
			if node1 == nil {
				prevNode.Next = node2
				break
			}
			if node2 == nil {
				prevNode.Next = node1
				break
			}
		}
		val := c
		if node1 != nil {
			val = val + node1.Val
		}
		if node2 != nil {
			val = val + node2.Val
		}

		c = val / 10
		val = val % 10

		var node *ListNode
		if node1 != nil {
			node = node1
		} else if node2 != nil {
			node = node2
		} else {
			node = &ListNode{}
		}
		node.Val = val
		if prevNode == nil {
			prevNode = node
		} else {
			prevNode.Next = node
			prevNode = prevNode.Next
		}
		if headNode == nil {
			headNode = prevNode
		}

		if node1 != nil {
			node1 = node1.Next
		}
		if node2 != nil {
			node2 = node2.Next
		}
		prevNode.Next = nil
	}
	return headNode
}

```