```
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        while head and head.val == val:
            head = head.next
        pointer_1=head
        if head:
            while pointer_1.next!=None:
                if pointer_1.next.val!=val:
                    pointer_1=pointer_1.next
                elif pointer_1.next.val==val:
                    if pointer_1.next.next!=None:
                        pointer_1.next=pointer_1.next.next
                    elif pointer_1.next.next==None:
                        pointer_1.next=None
        return head
    
```

# 代码块
```
