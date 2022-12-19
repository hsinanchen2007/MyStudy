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
func partition(head *ListNode, x int) *ListNode {
	
    beforePre := &ListNode{
        Val: 0,
        Next: nil,
    }
    afterPre := &ListNode{
        Val : 0,
        Next: nil,
    }
	beforeNode := beforePre
    afterNode := afterPre
    for nil != head {
        if head.Val < x {
            beforeNode.Next = head
            beforeNode = beforeNode.Next
        } else {
            afterNode.Next = head
            afterNode = afterNode.Next
        }
        head = head.Next
    }

    // 将两个链表连接
    afterNode.Next = nil
    beforeNode.Next = afterPre.Next
	return beforePre.Next
}
```