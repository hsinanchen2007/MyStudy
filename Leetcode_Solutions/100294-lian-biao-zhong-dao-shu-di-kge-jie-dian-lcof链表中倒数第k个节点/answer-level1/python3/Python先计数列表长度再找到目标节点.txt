### 解题思路
先遍历链表计算长度，再从头找出目标节点。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        count = 0
        node = head
        while node:
            count += 1
            node = node.next
        node = head
        n = count - k
        while n:
            node = node.next
            n -= 1
        return node
```