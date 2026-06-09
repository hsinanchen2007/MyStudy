### 解题思路
把两个链表接在一起

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        tA,tB=headA,headB
        while tA!=tB:
            tA=tA.next if tA else headB
            tB=tB.next if tB else headA
        return tA
      
```