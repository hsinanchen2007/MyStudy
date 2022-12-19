### 解题思路
使用快慢指针一定要注意快满指针的初始值问题，避免一步后慢指针就等于快指针

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
        quick, slow = head.next, head
        while quick and slow:
            if quick is slow:
                return True
            else:
                if quick.next is None:
                    return False
                quick = quick.next.next
                slow = slow.next
        return False
'''

        m = []
        while head:
            if head in m:
                return True
            else:
                m.append(head)
                head = head.next
        return False
'''
 
```