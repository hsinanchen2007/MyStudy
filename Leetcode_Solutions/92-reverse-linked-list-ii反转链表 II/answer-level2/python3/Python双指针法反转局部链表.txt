### 解题思路
用a，c两个指针定位局部链表的头尾，翻转后和之前的链表进行连接
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == n:
            return head
        dum = ListNode(-1)
        dum.next = head
        a,c = dum,dum
        for i in range(m-1):
            a = a.next
        for i in range(n):
            c = c.next
        b = a.next
        d = c.next
        pre = b
        cur = pre.next
        while cur != d:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        a.next = c
        b.next = d
        return dum.next
```