### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1: return l2
        if not l2: return l1
        if l1.val>l2.val:
            res=ListNode(l2.val)
            res.next=self.mergeTwoLists(l1,l2.next)
        else:
            res = ListNode(l1.val)
            res.next=self.mergeTwoLists(l1.next,l2)
        return res

```