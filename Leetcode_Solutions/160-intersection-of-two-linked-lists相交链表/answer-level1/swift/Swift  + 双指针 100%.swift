```
class Solution {
    func getIntersectionNode(_ headA: ListNode?, _ headB: ListNode?) -> ListNode? {
        if headA == nil || headB == nil {
            return nil
        }
        var curA = headA
        var curB = headB
        var shouldReturnA = false
        var shouldReturnB = false
        while curA != nil && curB != nil {
            if curA === curB {
                return curA
            }
            curA = curA?.next
            curB = curB?.next

            if curA == nil && !shouldReturnA {
                curA = headB
                shouldReturnA = true
            }
            if curB == nil && !shouldReturnB{
                curB = headA
                shouldReturnB = true
            }
        }
        return nil
    }
}
```