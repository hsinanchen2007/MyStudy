### 解题思路
遍历列表
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre_node = None
        node = head
        while(node):
            temp_next = node.next
            node.next = pre_node
            pre_node = node
            node = temp_next
        return pre_node
```