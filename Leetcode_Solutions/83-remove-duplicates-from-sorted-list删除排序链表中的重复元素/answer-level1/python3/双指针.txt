1. 链表题记得判空
2. 双指针，记录上一个位置，与当前位置

题目比较简单,直观感觉即可求解 
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return []
        dummy = ListNode(0)
        dummy.next = head
        pre = head
        cur = head.next
        while cur:
            if cur.val == pre.val:
                pre.next = cur.next
                cur = cur.next
            else:
                pre=cur
                cur=cur.next
        return dummy.next
```
