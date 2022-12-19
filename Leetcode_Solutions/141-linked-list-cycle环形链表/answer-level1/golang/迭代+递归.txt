### 解题思路
快慢双指针，若有环，指针必在环内相遇，若无则快指针必先指向nil

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// 迭代
func hasCycle(head *ListNode) bool {
    if head == nil {
        return false
    }
    slow,fast := head,head
    for fast != nil && fast.Next != nil  {
        slow = slow.Next
        fast = fast.Next.Next
        if slow == fast {
            return true
        }
    }
    return false
}

// 递归
func hasCycle(head *ListNode) bool {
    return  isCycle(head,head)
}

func isCycle(l1,l2 *ListNode) bool {
    if l2 == nil || l2.Next == nil {
        return false
    }
    if l1.Next == l2.Next.Next {
        return true
    }
    return isCycle(l1.Next,l2.Next.Next)
}

```