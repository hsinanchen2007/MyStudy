### 解题思路
1.建立一个Hash表，遍历ListA，遍历过程中把每个元素存到Hash表中。
2.遍历ListB，遍历过程中判断目前节点是否在Hash表中出现过，出现过则return目前节点。
3.遍历到结束都没有的话就直接返回None，说明不相交。
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
        hasht = {}
        while headA is not None:
            hasht[headA], headA = headA, headA.next
        while headB is not None:
            if headB in hasht: 
                return headB
            else:
                headB = headB.next
        return None

```