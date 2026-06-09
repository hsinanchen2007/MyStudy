总思路：先用快慢指针确认中点，然后将后半段翻转，最后两个交叉插入
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        if(not head):
            return []
        # 快慢指针确定中点
        slow = head
        fast = head
        last = None
        while(fast and fast.next):
            fast = fast.next.next
            last = slow
            slow = slow.next
        # 将链表分割成两半
        if(fast):
            right_head = slow.next
            slow.next = None
        else:
            right_head = slow
            last.next = None
        # 翻转链表
        last = None
        cur = right_head
        while(cur):
            last, cur.next, cur = cur, last, cur.next
        # 交叉合并链表
        right_head = last
        node1 = head
        node2 = right_head
        while(node1 and node2):
            node2.next, node1.next, node1, node2 = node1.next, node2, node1.next, node2.next
```
