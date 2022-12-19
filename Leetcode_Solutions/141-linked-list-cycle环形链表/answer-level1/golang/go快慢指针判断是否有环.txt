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

// type ListNode struct {
//     Val int
//     Next *ListNode
// }

func hasCycle(head *ListNode) bool {
    if nil == head || nil == head.Next {
        return false
    }
    // 利用快慢指针
    slow := head
    fast := head.Next
    for slow != fast {
        if nil == fast || nil == fast.Next {
            return false
        }
        slow = slow.Next
        fast = fast.Next.Next
    }
    return true
}
```