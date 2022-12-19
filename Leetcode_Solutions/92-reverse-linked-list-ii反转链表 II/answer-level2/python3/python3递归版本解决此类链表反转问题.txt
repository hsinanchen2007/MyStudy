```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 递归版本
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        # 全局变量
        self.successor = None
        # 反转前N个节点函数
        def reverseN(head, n):
            if n == 1:
                self.successor = head.next
                return head
            last = reverseN(head.next, n-1)
            head.next.next = head
            head.next = self.successor
            return last
        if m == 1:
            return reverseN(head,n)
        head.next = self.reverseBetween(head.next, m-1, n-1)
        return head
```
