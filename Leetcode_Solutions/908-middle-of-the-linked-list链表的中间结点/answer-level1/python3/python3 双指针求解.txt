### 解题思路
双指针
慢指针每次跳一下
快指针每次跳两下
快指针到末尾的时候，慢指针刚好到中间结点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        point1 = head
        point2 = head
        while point2 and point2.next:
            point1 = point1.next
            point2 = point2.next.next
        return point1
```