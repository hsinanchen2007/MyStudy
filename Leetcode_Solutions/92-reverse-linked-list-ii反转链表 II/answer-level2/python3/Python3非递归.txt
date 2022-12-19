```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# class Solution:
#     # 递归版本
#     def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
#         # 全局变量
#         self.successor = None
#         # 反转前N个节点函数
#         def reverseN(head, n):
#             if n == 1:
#                 self.successor = head.next
#                 return head
#             last = reverseN(head.next, n-1)
#             head.next.next = head
#             head.next = self.successor
#             return last
#         if m == 1:
#             return reverseN(head,n)
#         head.next = self.reverseBetween(head.next, m-1, n-1)
#         return head
class Solution:
    # 非递归版本
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        # 重点是找到m前一个pre
        cur = head
        pre = None
        tail = None
        cnt = 0
        while cur:
            cnt += 1
            pre = cur if cnt == m - 1 else pre
            tail = cur if cnt == n + 1 else tail
            cur = cur.next
        if m > n or m < 1 or n > cnt:
            return head
        start = head if pre is None else pre.next
        cur = start.next
        start.next = tail
        # 反转逻辑
        while cur != tail:
            next = cur.next
            cur.next = start
            start = cur
            cur = next
        if pre:
            # fuck 我这里写成了"=="。。。。黑人问号脸
            pre.next = start
            return head
        return start
```
