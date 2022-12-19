### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head

        pre = dummy
        end = dummy

        while end.next:
            for _ in range(k):
                end = end.next
                if not end:break
            if not end:break

            start = pre.next
            next_p = end.next
            end.next = None
            pre.next = self.reverse(start)
            start.next = next_p
            
            pre = start
            end = pre

        return dummy.next

    def reverse(self, head):

        pre = None
        cur = head

        while cur:
            next_p = cur.next
            cur.next = pre

            pre = cur
            cur = next_p

        return pre








```