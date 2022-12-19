### 解题思路
双指针法，每次双指针相交的节点，总是链表入口的前一个节点

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
    res := hasCycle(head) 
    if res == nil {
        return nil
    }
    for head != res {
        head = head.Next
        res = res.Next
    }
    return res
}

func hasCycle(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
    firstNode, secondNode := head, head 
	for secondNode != nil && secondNode.Next != nil {
		firstNode = firstNode.Next
		secondNode = secondNode.Next.Next
        if firstNode == secondNode {
			return secondNode
		}
	}
	return nil
}

// func detectCycle(head *ListNode) *ListNode {
// 	fast := head
// 	slow := head
// 	hasCyc := false
// 	for fast != nil && fast.Next != nil {
// 		fast = fast.Next.Next
// 		slow = slow.Next
// 		if fast == slow {
// 			hasCyc = true
// 			break
// 		}
// 	}
// 	if !hasCyc {
// 		return nil
// 	}
// 	slow = head
// 	for fast != slow {
// 		slow = slow.Next
// 		fast = fast.Next
// 	}
// 	return fast
// }
```