### 解题思路
遍历链表两次，一次得到链表长度，一次取出中间节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        n = 0
        cur = head
        while cur:
            n += 1
            cur = cur.next
        i = 0
        cur = head
        while i < n// 2:
            i += 1
            cur = cur.next
        return cur
```