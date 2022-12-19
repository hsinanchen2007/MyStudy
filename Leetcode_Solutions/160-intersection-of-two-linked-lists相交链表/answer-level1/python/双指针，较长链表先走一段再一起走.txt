### 解题思路
1. 先分别统计两个链表的长度，la, lb
2. 分别让两个指针指向链表的开头，让较长的链表指针先走abs(la - lb）步
3. 让两个指针同时走，如果指针指向相同节点，返回该节点。若走到最后无相同节点，返回None

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB:
            return None
        nodeA, nodeB = headA, headB
        la, lb = 0, 0
        while nodeA:
            la += 1
            nodeA = nodeA.next
        while nodeB:
            lb += 1
            nodeB = nodeB.next
        nodeA, nodeB = headA, headB
        diff = abs(lb - la)
        if la < lb:
            for _ in range(diff):
                nodeB = nodeB.next
        else:
            for _ in range(diff):
                nodeA = nodeA.next
        while nodeA and nodeB:
            if nodeA == nodeB:
                return nodeA
            nodeA = nodeA.next
            nodeB = nodeB.next
        return None
```