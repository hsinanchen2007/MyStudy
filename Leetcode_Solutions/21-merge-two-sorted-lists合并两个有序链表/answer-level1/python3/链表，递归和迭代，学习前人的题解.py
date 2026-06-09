```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        #递归，函数的嵌套
        # if l1 and l2:
        #     if l1.val>=l2.val: l1,l2=l2,l1
        #     l1.next = self.mergeTwoLists(l1.next,l2)
                
        # return l1 or l2

        #迭代
        if not l1 and l2:return l2
        if l1 and not l2:return l1
        #头结点不动 prevhead
        #哨兵结点移动 prev
        prevhead = ListNode(-1)
        prev = prevhead
        while l1 and l2:
            if l1.val>l2.val:
                prev.next=l2
                l2 = l2.next
            else:
                prev.next = l1
                l1 = l1.next
            #哨兵结点移动
            prev = prev.next
        #当l1和l2长度不同时，谁不为空，哨兵就指向谁
        prev.next = l1 if l1 else l2

        return prevhead.next
        

```
