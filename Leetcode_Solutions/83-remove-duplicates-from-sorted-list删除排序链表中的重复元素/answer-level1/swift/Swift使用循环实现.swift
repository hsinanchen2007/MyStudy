class Solution {
    
    func deleteDuplicates(_ head: ListNode?) -> ListNode? {
        let dummyNode: ListNode = ListNode(0)
        dummyNode.next = head
        var pre: ListNode? = dummyNode
        var cur: ListNode? = head
        var mapSet = Set<Int>()
        while let mcur = cur {
            if (mapSet.contains(mcur.val)) {
                pre?.next = mcur.next
                cur = mcur.next
            } else {
                mapSet.insert(mcur.val)
                pre = mcur
                cur = mcur.next
            }
        }
        return dummyNode.next
    }
}