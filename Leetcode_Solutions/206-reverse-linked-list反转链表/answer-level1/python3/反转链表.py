### 解题思路
此处撰写解题思路
逐次取下原来链表的结点作为新链表的头结点，这样旧链表不断变短，新链表逐渐增长
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        newhead = None
        while head:
            temp = head.next
            head.next = newhead
            newhead = head
            head = temp
        return newhead


```