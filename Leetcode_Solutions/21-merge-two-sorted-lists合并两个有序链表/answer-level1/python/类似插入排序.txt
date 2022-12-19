### 解题思路
时间复杂度：O(m+n)
空间复杂度：O(m+n)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        merged = next_node = None
        while l1 and l2:
            new_node = ListNode(l1.val if l1.val < l2.val else l2.val)
            if not merged:
                merged = new_node
                next_node = merged
            else:
                next_node.next = new_node
                next_node = new_node
            if new_node.val == l1.val:
                l1 = l1.next
            else:
                l2 = l2.next    
        if l1:
            if not merged:
               merged = l1
            else:
                next_node.next = l1
        if l2:
            if not merged:
                merged = l2
            else:
                next_node.next = l2
        return merged

```