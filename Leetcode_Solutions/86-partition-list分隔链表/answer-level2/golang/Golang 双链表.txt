

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
  if head == nil || head.Next == nil {
    return head
  }
  
  var i, n *ListNode
  
  l := &ListNode{
    Next: nil,
  }
  lt := l
  
  b := &ListNode{
    Next: nil,
  }
  bt := b
  
  i = head
  for i != nil {
    n = i.Next
    if i.Val < x {
      i.Next = lt.Next
      lt.Next = i
      lt = i
    } else {
      i.Next = bt.Next
      bt.Next = i
      bt = i
    }
    i = n
  }
  
  lt.Next = b.Next
  
  return l.Next
}
```