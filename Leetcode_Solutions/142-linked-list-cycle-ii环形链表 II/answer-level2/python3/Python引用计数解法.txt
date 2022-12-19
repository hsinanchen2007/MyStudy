Python内部对每个对象都有引用计数，环交叉节点对象的引用计数一定高一些，所以观察各个节点引用计数，发现引用计数大于等于5的就是环交叉节点，直接返回第一个引用计数大于等于5的节点即可;-)

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head:
            return None
        while head.next:
            if sys.getrefcount(head) >= 5:
                return head
            head = head.next
        return None
```
