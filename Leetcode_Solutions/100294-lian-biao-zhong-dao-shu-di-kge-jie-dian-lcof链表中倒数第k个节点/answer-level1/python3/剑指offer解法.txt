```
def getKthFromEnd(head, k):
    if head == None or k == 0:
        return None
    pA, pB = head, head
    for i in range(k-1):
        if pA.next != None:  # 判断链表节点是否小于k
            pA = pA.next
        else:
            return None

    while pA.next != None:
        pA = pA.next
        pB = pB.next

    return pB

```
