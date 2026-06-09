    /**
    * Definition for singly-linked list.
    * public class ListNode {
    *     public var val: Int
    *     public var next: ListNode?
    *     public init(_ val: Int) {
    *         self.val = val
    *         self.next = nil
    *     }
    * }
    */
    class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
            var result: ListNode? = nil

            if l1 == nil && l2 == nil {
                return result
            }
            
            var h1 = l1
            var h2 = l2
            var sum = (h1?.val ?? 0) + (h2?.val ?? 0)
            if sum >= 10 {
                sum = sum % 10
                h1 = h1?.next ?? ListNode(0)
                h1!.val = h1!.val + 1
            }else {
                h1 = h1?.next
            }
            result = ListNode(sum)
            h2 = h2?.next
            result!.next = addTwoNumbers(h1, h2)
            
            return result
        }
    }