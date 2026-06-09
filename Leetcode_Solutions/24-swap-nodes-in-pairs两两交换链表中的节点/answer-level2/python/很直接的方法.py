### 解题思路
此处撰写解题思路
How can the input being `[]`????

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        try:
            if head.next is None:
                return head

            elif head.next.next is None:
                # only 2 links
                current_head = head
                next_head = head.next
                next_head.next = current_head
                next_head.next.next = None
                return next_head
            else:
                current_head = head
                next_head = head.next
                third_head = next_head.next
                next_head.next = current_head
                current_head.next = self.swapPairs(third_head)
                return next_head
        except AttributeError:
            return None
```