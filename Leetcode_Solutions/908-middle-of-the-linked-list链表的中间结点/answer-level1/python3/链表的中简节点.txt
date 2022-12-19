### 解题思路
双指针，快指针步长为2，慢指针步长为1，当快指针的next存在,next.next不存在，返回慢指针的.next,当next不存在，返回慢指针


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        k1 = head
        k2 = head
        while k2.next and k2.next.next:
            k2 = k2.next.next
            k1 = k1.next
        if k2.next:
            return k1.next
        return k1
```