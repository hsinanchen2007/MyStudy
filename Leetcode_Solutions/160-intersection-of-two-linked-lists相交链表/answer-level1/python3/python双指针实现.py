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
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        pA=headA
        pB=headB
        while pA!=pB:
            pA=pA.next
            pB=pB.next
            if not pA and not pB:
                return None
            if not pA:
                pA=headB
            if not pB:
                pB=headA
        return pA
```