思路：首先把前k个链表看成一个子链表，然后进行翻转，我觉得第一组k跟其他组的k不同，涉及到返回值的问题，因此分成了第一组k个剩下的k
```
def ReserveK(head,k):
    if head == None or head.next == None:
        return head

    cur = head

    end = head
    pre = head
    i = 1
    while i != k:
        if end == None:
            return head
        end = end.next
        i += 1

    head = end
    while cur != end:
        next = cur.next
        cur.next = end.next
        end.next = cur
        cur = next
    end = pre.next
    cur = pre.next
    while cur != None:
        i = 1
        # print(end.data)
        while i != k:
            end = end.next
            if end == None:
                return head
            i += 1
        pre.next = end
        pre = cur
        while cur != end:
            next = cur.next
            cur.next = end.next
            end.next = cur
            cur = next
        end = pre.next
        cur = pre.next
    return head
```
