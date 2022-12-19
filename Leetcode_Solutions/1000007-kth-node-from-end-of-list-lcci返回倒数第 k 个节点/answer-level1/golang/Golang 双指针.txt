

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func kthToLast(head *ListNode, k int) int {
    i := 0
    left,right := head,head
    for right != nil{
        if i >= k{
            left = left.Next
        }
        right = right.Next
        i++
    }
    return left.Val
}
```