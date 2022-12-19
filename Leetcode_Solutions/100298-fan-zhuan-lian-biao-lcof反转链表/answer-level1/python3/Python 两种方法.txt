### 解题思路
第一种：借助新的list将原来的数都存下来，然后逆序生成新的链表

第二种：借助两个指针，不断地将后一个指针指向的节点的next指向前一个指针

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        t = head
        a = []
        while t:
            a.append(t.val)
            t = t.next
        dummy = ListNode(None)
        h = dummy
        for i in a[::-1]:
            tt = ListNode(i)
            h.next = tt
            h = h.next
        return dummy.next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre = head
        cur = None
        while pre:
            t = pre.next
            pre.next = cur
            cur = pre
            pre = t
        return cur

```