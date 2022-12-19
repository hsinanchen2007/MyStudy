### 解题思路
记录一下，第一次用到快慢双指针

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # 快慢双指针，如果有环，则单链表中的元素一直存在next，快慢指针总会相遇，就能突破while循环
        slow = fast = head
        # 判断加上fast.next排除单元素链表（肯定不能形成环，直接return False）
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                return True
        return False
```