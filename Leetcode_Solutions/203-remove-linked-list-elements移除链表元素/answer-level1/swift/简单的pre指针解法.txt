```
class Solution {
    func removeElements(_ head: ListNode?, _ val: Int) -> ListNode? {
        if var head_ = head {
            let preNode = ListNode(-1)
            var prev = preNode
            prev.next = head_
            while head_.next != nil {

                if head_.val == val {
                    prev.next = head_.next
                    head_ = head_.next!
                }else {
                    prev = head_
                    head_ = head_.next!
                }

            }

            if head_.val == val {
                prev.next = nil
            }

            return preNode.next
        }else {
            return nil
        }
    }
}
```
