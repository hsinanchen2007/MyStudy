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
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1 
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1 
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2

        # 方法2
        # cur = dum = ListNode(0)    # 借用额外的变量，不明白为什么一定需要dum
        # while l1 and l2:
        #     if l1.val < l2.val:
        #         cur.next, l1 = l1, l1.next
        #     else:
        #         cur.next, l2 = l2, l2.next
        #     cur = cur.next
        # cur.next = l1 if l1 else l2
        # return dum.next

        

```