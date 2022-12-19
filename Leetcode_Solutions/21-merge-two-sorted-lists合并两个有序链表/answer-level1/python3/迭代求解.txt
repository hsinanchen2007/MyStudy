### 解题思路


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        nNode = ListNode(-1)
        pNode = nNode
        while l1 != None and l2 != None:
            if l1.val <= l2.val:
                pNode.next = l1
                l1 = l1.next
            else:
                pNode.next = l2
                l2 = l2.next
            pNode = pNode.next
        pNode.next = l2 if l1 == None else l1
        
        return nNode.next



```