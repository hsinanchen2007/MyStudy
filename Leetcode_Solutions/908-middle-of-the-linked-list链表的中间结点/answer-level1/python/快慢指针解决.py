### 解题思路
快慢指针的应用,通过挺慢指针,快指针比慢指针多走一步,快指针到链表尾部的时候,慢指针刚好到中间.

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        p=head
        p1=head
        while p1 and p1.next:
            p=p.next
            p1=p1.next
            if p1:
                p1=p1.next
            else:
                break
        return p
```
