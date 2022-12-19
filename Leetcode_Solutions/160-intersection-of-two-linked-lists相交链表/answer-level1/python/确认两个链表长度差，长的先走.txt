### 解题思路
总共走两轮：第一轮两个指针一起走，其中一个先到None，记录另一个位置，第二轮判断先走的指针和先走的距离，然后两个链表指针一起走（不相交则同时到达None）。
虽然没有官方方法三有灵性，但是复杂度上是差不多的。
![image.png](https://pic.leetcode-cn.com/28f464166414b8fb177e5ba71f1100fe105b52edcb77df1a470d4ddda3ec1ce1-image.png)

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
        if headA == None or headB == None:
            return None
        pA, pB = headA, headB
        while pA and pB:
            pA = pA.next
            pB = pB.next
        if pA:
            pAA, pB = headA, headB
            while pA:
                pA = pA.next
                pAA = pAA.next
            while pAA != pB:
                pAA = pAA.next
                pB = pB.next
                if pAA == None:
                    return None
            return pAA
        else:
            pA, pBB = headA, headB
            while pB:
                pB = pB.next
                pBB = pBB.next
            while pA != pBB:
                pA = pA.next
                pBB = pBB.next
                if pA == None:
                    return None
            return pA
```