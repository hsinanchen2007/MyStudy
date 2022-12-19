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
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    var head *ListNode
    var cur, pre *ListNode
    if l1 == nil && l2 == nil {
        return nil
    } else if l1 == nil {
        return l2
    } else if l2 == nil {
        return l1
    }
    
    for l1 != nil && l2 != nil {
        if l1.Val <= l2.Val {
            cur = l1
            l1 = l1.Next
        } else {
            cur = l2
            l2 = l2.Next
        }
        if pre == nil {
            pre = cur
        } else {
            pre.Next = cur
            pre = cur
        }
        if head == nil {
            head = cur
        }
    }
    if l1 != nil {
        cur.Next = l1
    } else if l2 != nil {
        cur.Next = l2
    } else {
        cur.Next = nil
    }
    return head
}
```