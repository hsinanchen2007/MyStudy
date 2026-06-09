

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
     if head == nil || k==0{
        return nil
    }
    dummnyhead := &ListNode{Val:-1,Next:head}
    fast,slow := dummnyhead,dummnyhead
    for i :=0;i<k;i++{
        if fast.Next != nil{
              fast = fast.Next 
        }else{
            return nil
        }
    }
    for fast != nil && fast.Next!= nil{
        fast = fast.Next
        slow = slow.Next
    }
    return slow.Next
}
```