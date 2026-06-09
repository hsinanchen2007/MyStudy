```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    if head == nil || head.Next == nil{
        return head 
    }
    var prev = &ListNode{Next:head}
    var cur = prev.Next
    third := cur.Next
    cur.Next = third.Next
    third.Next = prev.Next
    prev.Next = third
    cur.Next =swapPairs(cur.Next)
    return prev.Next 
}
```
