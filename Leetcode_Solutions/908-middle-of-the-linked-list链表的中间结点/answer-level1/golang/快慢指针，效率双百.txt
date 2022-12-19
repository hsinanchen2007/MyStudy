### 解题思路
使用快慢指针，慢指针走一格，快指针走两格。快指针遍历完，返回慢指针。注意边界情况和初始情况的处理。
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
    if head == nil || head.Next == nil {
        return head
    }
    if head.Next.Next == nil {
        return head.Next
    }
    SlowPointer := head.Next
    FastPointer := head.Next.Next
    
    for FastPointer.Next != nil && FastPointer.Next.Next != nil {
        SlowPointer = SlowPointer.Next
        FastPointer = FastPointer.Next.Next
    }
    if FastPointer.Next == nil {
        return SlowPointer
    }
    return SlowPointer.Next

}
```