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
        #思路：a+c+b=b+c+a 
        p1=headA
        p2=headB
        while p1 != p2:
            # p1走完直接连接到headB
            if p1==None:
                p1=headB
            else:
                p1=p1.next
            # p2走完直接连接到headA
            if p2==None:
                p2=headA
            else:
                p2=p2.next
        return p1
```