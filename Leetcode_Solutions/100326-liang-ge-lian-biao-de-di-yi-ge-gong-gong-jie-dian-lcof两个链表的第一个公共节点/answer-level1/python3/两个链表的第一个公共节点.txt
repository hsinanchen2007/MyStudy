### 解题思路
我们先把全部结点分别压入两个栈，利用栈的特性后进先出特性，同时pop出栈，一开始两边的元素肯定是相同的，当遇到不同的元素时，肯定已经遇到了最后一个节点，那就结束找到commonNode

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA is None:
            return None
        if headB is None:
            return None
        headAArray = []
        headBArray = []
        tempA = headA
        while tempA != None:
            headAArray.append(tempA)
            tempA = tempA.next
        tempB = headB
        while tempB != None:
            headBArray.append(tempB)
            tempB = tempB.next
        commonNode = None
        while headAArray and headBArray:
            node1 = headAArray.pop()
            node2 = headBArray.pop()
            if node1 != node2:
                break
            else:
                commonNode = node1
        return commonNode
        
        
```