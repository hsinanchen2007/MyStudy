```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:

        copy_node = ListNode(0)
        copy_node.next = head

        # 计算链表长度
        c = 0
        while head:
            c += 1
            head = head.next

        # 正向 k 的位置
        tag_value = c - k + 1

        d = 0
        while copy_node:
            d += 1
            if d == tag_value:
                return copy_node.next

            copy_node = copy_node.next
```
