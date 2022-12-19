快指针一次走两步，慢指针一次走一步，如果没有环，快指针的.next或者next.next 则会先为空，即返回false， 如果有环，快指针一定会追上慢指针，所以当快指针等于慢指针说明有环
```
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return false
    }
    qNode := head.Next
    sNode := head
    for qNode != sNode {
        if qNode.Next == nil || qNode.Next.Next == nil {
            return false
        }
        sNode = sNode.Next
        qNode = qNode.Next.Next
    }
    return true
}
```
