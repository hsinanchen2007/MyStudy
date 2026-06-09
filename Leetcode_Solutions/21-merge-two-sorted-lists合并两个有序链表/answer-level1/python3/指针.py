### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)

        i = l1
        j = l2
        k = head
        while i != None and j != None:
            if i.val == j.val:
                # new two listnodes
                n1 = ListNode(i.val)
                n2 = ListNode(j.val)
                # link
                k.next = n1
                n1.next = n2
                # next
                k = n2
                i = i.next
                j = j.next


            elif i.val < j.val:
                # new one listnode
                n1 = ListNode(i.val)
                # link
                k.next = n1
                # next
                k = n1
                i = i.next

            else:
                # new one listnode
                n2 = ListNode(j.val)
                # link
                k.next = n2
                # next
                k = n2
                j = j.next


        if i != None:
            k.next = i
        
        if j != None:
            k.next = j

        return head.next

```