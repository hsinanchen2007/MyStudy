### 解题思路
注意结束条件

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
    temp := &ListNode{0, head,}
    slow, fast := temp, temp
    for fast != nil && fast.Next != nil {
        fast = fast.Next
        fast = fast.Next

        slow = slow.Next
    }
    if fast == nil {
        return slow
    } else {
        return slow.Next
    }
    
}
```