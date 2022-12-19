def reverseList(self, head: ListNode) -> ListNode:
        pre = None
        cur = head

        while cur:
            tmp = cur.next

            cur.next = pre

            pre = cur
            cur = tmp
        
        return pre