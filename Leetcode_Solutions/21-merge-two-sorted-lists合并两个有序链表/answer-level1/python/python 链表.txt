### 解题思路
这里要注意开辟一个新的内存空间l3时，p3.next接上新的节点以后，p3要自移位p3 = p3.next


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:

        p1 = l1
        p2 = l2
        p3 = l3 = ListNode(-1)

        while p1 and p2:
            if p1.val <= p2.val:
                p3.next = p1
                p1 = p1.next
            else:
                p3.next = p2
                p2 = p2.next
            p3 = p3.next
        print(l3)
        if p1 or p2:
            p3.next = p1 or p2

        return l3.next
```