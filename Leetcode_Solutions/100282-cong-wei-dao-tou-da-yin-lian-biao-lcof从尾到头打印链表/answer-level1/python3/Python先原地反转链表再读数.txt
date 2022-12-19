### 解题思路
先在原地反转链表。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        num = []
        pre_node = None
        node = head
        while node:
            tmp = node.next
            node.next = pre_node
            pre_node = node
            node = tmp
        node = pre_node
        while node:
            num.append(node.val)
            node = node.next
        return num
```