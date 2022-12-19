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
        cura = headA
        curb = headB
        lena = 0
        lenb = 0
        while headA:
            lena+=1
            headA = headA.next
        while headB:
            lenb+=1
            headB = headB.next
        while cura:
            if lenb>lena:
                curb = curb.next
                lenb-=1
            elif lena>lenb:
                cura = cura.next
                lena-=1
            elif lena == lenb:
                if cura == curb:
                    return cura
                else:
                    cura = cura.next
                    curb = curb.next
                    lena -= 1
                    lenb -= 1
        return None
```