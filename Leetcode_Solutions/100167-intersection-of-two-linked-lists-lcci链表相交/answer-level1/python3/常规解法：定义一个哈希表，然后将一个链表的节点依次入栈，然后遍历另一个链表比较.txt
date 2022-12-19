### 解题思路
直接比较链表节点，而不是比较节点值，就满足了题目要求（引用相同）

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        hash_dict={}
        while headA:
            hash_dict[headA],headA=headA,headA.next
        while headB:
            if headB in hash_dict:
                return headB

            headB=headB.next
    
        return None
```