### 解题思路
创建两条新链表，根据val分别连接，最后再拼接再一齐

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        less_head = ListNode(0)
        more_head = ListNode(0)
        less_ptr = less_head
        more_ptr = more_head
        while head:
            if head.val < x:
                less_ptr.next = head
                less_ptr = head
            else:
                more_ptr.next = head
                more_ptr = head
            head = head.next
        
        less_ptr.next = more_head.next
        more_ptr.next = None
        return less_head.next
```