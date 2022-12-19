### 解题思路
如下代码所示，利用OOP的object可以存访属性的特性，标记每个Node是否已被访问过。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head:
            return False
        current, has_cycle = head, False
        while current.next:
            visited = 
            if getattr(current, "visited", False):
                has_cycle = True
                break
            else:
                setattr(current, "visited", True)
            current = current.next
        return has_cycle
```