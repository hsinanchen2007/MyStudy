### 解题思路


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        node_id_list = []
        p = head
        while p:
            if id(p) in node_id_list:
                return True
            else:
                node_id_list.append(id(p))
                p = p.next
        return False

```