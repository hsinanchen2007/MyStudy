### 解题思路

大哥为了刺杀仇家带头遍历链表，尾随小弟形影不离。

当大哥总算找到仇家时，身后的小弟暗中冷笑，将大哥和仇家一同消灭，直接接棒大哥的所有生意，成为新一代话事人。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if head is None:
            return None
        if head.val == val:
            return head.next
        pre = cur = head
        while cur:
            if cur.val == val:
                pre.next = cur.next
                break
            pre = cur
            cur = cur.next
        return head
```