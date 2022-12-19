```class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        guard l1 != nil || l2 != nil else {
            return nil
        }
        let sum = (l1?.val ?? 0) + (l2?.val ?? 0)
        let result = ListNode.init(sum % 10)
        if sum >= 10 {
            let node = l1 ?? l2!
            let next = node.next ?? ListNode.init(0)
            next.val += 1
            node.next = next
        }
        result.next = addTwoNumbers(l1?.next, l2?.next)
        return result
    }
}```