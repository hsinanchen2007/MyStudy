### 解题思路
1. 利用快慢指针来解决问题，fast走两步，slow走一步，当fast走完的时候，slow正好走到中间
2. 利用单指针来解决，遍历链表统计长度

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
```