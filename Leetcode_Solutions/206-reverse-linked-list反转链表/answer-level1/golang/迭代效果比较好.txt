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
func recursive(node *ListNode) *ListNode  {
    if node == nil {
		return nil
	}
	if node.Next == nil {
		return node
	}
	n1 := node
	n2 := recursive(node.Next)
	t := n2
	for t.Next != nil {
		t = t.Next
	}
	t.Next = n1
	n1.Next = nil
	return n2
}

func iterate(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
	t1 := head
	t2 := head.Next
	t1.Next = nil

	for t2 != nil {
		t := t2
        t2 = t2.Next
		t.Next = t1
		t1 = t
	}
	return t1
}

func reverseList(head *ListNode) *ListNode {
	return iterate(head)
}
```