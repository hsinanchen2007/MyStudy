### 解题思路
常规套路删除节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        temp_node = head
        found = False
        if temp_node.val == val:
            head = head.next
            return head
        while temp_node.next and not found:
            if temp_node.next.val == val:
                found = True
                break
            temp_node = temp_node.next
        if found:
            temp_node.next = temp_node.next.next
        return head
```

