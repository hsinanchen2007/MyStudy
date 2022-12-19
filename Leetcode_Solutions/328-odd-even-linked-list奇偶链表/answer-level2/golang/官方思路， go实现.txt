### 解题思路
官方思路， go实现
同时赋值的语法类似python

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 // O(n), O(1)
func oddEvenList(head *ListNode) *ListNode {
    if head  == nil {
        return head
    }
    odd := head
    evenHead, even := head.Next,head.Next
    for even != nil && even.Next != nil {
        odd, odd.Next = odd.Next.Next, odd.Next.Next
        even, even.Next = even.Next.Next, even.Next.Next
    }
    odd.Next = evenHead
    return head
}
```