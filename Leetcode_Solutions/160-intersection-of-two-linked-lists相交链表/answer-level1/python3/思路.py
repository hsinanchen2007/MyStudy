### 解题思路
先对比两条链表的长度，然后移动相同长度的head起点，开始对比，寻找相同的节点返回，若没有则返回None

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        lenA = self.getlen(headA)
        lenB = self.getlen(headB)
        if lenA > lenB:  # A链表比B链表长
            headA = self.move_link(lenA, lenB, headA)
        else:
            headB = self.move_link(lenA, lenB, headB)
        
        while headA and headB:
            if headA == headB:
                return headB
            headA = headA.next
            headB = headB.next
        return None
            

    # 移动较长的链表的head为同一长度
    def move_link(self, lenA: int, lenB: int, head: ListNode) -> ListNode:
        detal = abs(lenA - lenB)
        while head and detal:
            head = head.next
            detal -= 1
        return head
            
    # 计算链表的长度
    def getlen(self, head: ListNode) -> int:
        length = 0
        while head:
            length += 1
            head = head.next
        return length
```