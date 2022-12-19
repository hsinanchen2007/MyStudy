### 解题思路
公共节点意味着这个公共节点后的所有节点都是共有的。因此若从链表末尾开始计数，公共节点的下标不可能大于长度较小链表的长度。较长链表长度大于较小链表的部分不可能存在共有节点，所以从最小长度链表的表头开始逐一比较即可。复杂度位O(n)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        def findLength(head):
            l = 0
            while head != None:
                head = head.next
                l += 1
            return l
        l1 = findLength(headA)
        l2 = findLength(headB)
        if l1 < l2:
            t = l2 - l1
            for i in range(t):
                headB = headB.next
            while headA != headB:
                headB = headB.next
                headA = headA.next
            return headA
        else:
            t = l1 - l2
            for i in range(t):
                headA = headA.next
            while headA != headB:
                headB = headB.next
                headA = headA.next
            return headA
```