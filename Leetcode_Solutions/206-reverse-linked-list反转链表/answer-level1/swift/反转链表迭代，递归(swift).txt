```
   // 迭代
    func reverseList(_ head: ListNode?) -> ListNode? {
        var curNode: ListNode? = head
        var resultNode: ListNode?
        while curNode != nil{
            let preNode = curNode!.next
            curNode!.next = resultNode
            resultNode = curNode
            curNode = preNode
        }
        return resultNode
    }
    // 递归
        func reverseList(_ head: ListNode?) -> ListNode? {
        guard let newHead = head, let newNextH = head?.next else {
            return head
        }
        let preNode = reverseList(newNextH)
        newHead.next?.next = newHead
        newHead.next = nil
        return preNode
        
    }
```