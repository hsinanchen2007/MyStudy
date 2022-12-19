```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if head is None: return head
        TempHead = ListNode(0)
        TempHead.next = head
        pre, cur = head, head.next
        while cur != None:
            if cur.val < pre.val:
                temp = cur.next
                insert_temp = TempHead
                while insert_temp.next.val < cur.val:
                    insert_temp = insert_temp.next
                cur.next = insert_temp.next
                insert_temp.next = cur
                cur = temp
                pre.next = cur
            else:
                cur = cur.next
                pre = pre.next
        return TempHead.next

```