### 解题思路
还是非递归方便hhh

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None

        ans = ListNode(head.val)
        head = head.next
        while head:
            tmp = ans
            ans = head
            head = head.next
            ans.next = tmp
        return ans
```