### 解题思路
如题

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        nodes_item = {}
        while l1 != None:
            nodes_item[l1] = l1.val
            l1 = l1.next
        while l2 != None:
            nodes_item[l2] = l2.val
            l2 = l2.next
        nodes = sorted(nodes_item.items(), key=lambda item: item[1])
        for i in range(len(nodes) - 1):
            nodes[i][0].next = nodes[i + 1][0]
            nodes[i + 1][0].next = None
        return nodes[0][0]
```