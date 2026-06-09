def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 and l2:
            top = head = l2 if l2.val <= l1.val else l1
            p = head.next
            q = l1 if l2.val <= l1.val else l2
            while p:
                head.next = p if p.val <= q.val else q
                if p.val <= q.val:
                    p = p.next
                    q = q
                else:
                    p ,q = q,p
                    p = p.next
                head = head.next
            head.next = q
            return top
        else:
            return l1 if l1 else l2