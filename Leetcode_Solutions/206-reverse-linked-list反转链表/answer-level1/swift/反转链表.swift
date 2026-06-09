class Solution {
    func reverseList(_ head: ListNode?) -> ListNode? {
        guard var headNode = head else {
            return nil
        }
        let list = ListNode.init(headNode.val)
        var newHead = list
        while let next = headNode.next {
            let newNode = ListNode.init(next.val)
            newNode.next = newHead
            newHead = newNode
            headNode = next
        }
        return newHead
    }
}