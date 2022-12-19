### 解题思路
1.链表要记得设置指针
2.若有一个链表的指针已经指到末尾，则一直输出0，直至两个链表都指到末尾

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l3 = ListNode(0)
        t3 = l3
        t1, t2 = l1, l2
        c = 0
        while t1 or t2:
            x = t1.val if t1 else 0
            y = t2.val if t2 else 0
            s = x + y + c
            t3.next = ListNode(s%10)
            t3 = t3.next
            c = 1 if s > 9 else 0
            if t1:
                t1 = t1.next
            if t2:
                t2 = t2.next
        if c:
            t3.next = ListNode(1)
        return l3.next

```