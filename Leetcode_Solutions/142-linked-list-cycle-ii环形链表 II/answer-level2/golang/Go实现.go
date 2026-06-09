```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func MeetNode(head *ListNode)*ListNode{
    if head == nil{
        return nil
    }
    fast,slow := head,head
    for fast!= nil&&fast.Next != nil{
        fast = fast.Next.Next
        slow = slow.Next
        if fast == slow{
            return slow
        }
        } 
    return nil
    }
    
    
func detectCycle(head *ListNode) *ListNode {
    if head == nil{
        return  nil      
    }

    meetNode := MeetNode(head)
    if meetNode ==nil{
        return nil
    }
    p := head
    for p != meetNode{
        p = p.Next
        meetNode = meetNode.Next
    }
    return p
    }
```
