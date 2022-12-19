```
        #1迭代
        if not head:
            return head
        l1 = None
        l2 = head
        while l2:
            l3 = l2.next
            l2.next = l1
            l1 = l2
            l2 = l3
        return l1

        #2递归
        if not head or not head.next:
            return head
        newhead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return newhead
```
