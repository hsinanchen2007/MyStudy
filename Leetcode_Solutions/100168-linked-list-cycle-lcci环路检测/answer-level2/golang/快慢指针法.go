快慢指针法
```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
    if(head == nil || head.Next == nil) {
        return nil
    }
    slow := head        // 开始时，快慢指针都指向头结点
    fast := head
    var meet *ListNode
    for fast != nil && fast.Next != nil {
        // 如果不存在环，快指针会先遍历完
        slow = slow.Next        // 链表没结束，快慢指针没相遇，慢指针一次往后走一步，快指针一次两步
        fast = fast.Next.Next  
        if(slow == fast) {      // 链表没结束，快慢指针相遇，有环，提前跳出
            meet = slow         // 快慢指针相遇点一定在环中，但不一定是环的起点
            break
        }
    }
    if(meet == nil) {           // 遍历链表结束，快慢指针没有相遇，则链表中不存在环
        return nil
    }

    p := head                   // 快慢指针能相遇，有环，则头结点和相遇处依次往后移动一个节点，再次相遇处则为环的起始节点
    for p != meet {
        p = p.Next
        meet = meet.Next
    }
    return p
}   

```
