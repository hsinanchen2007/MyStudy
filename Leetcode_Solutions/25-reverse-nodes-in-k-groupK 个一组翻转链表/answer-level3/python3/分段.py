```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#递归解法
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next: return head
        cur = head
        l = k
        while l > 1:
            cur = cur.next
            l -=1
            if not cur:
                return head
        #cur 旨在第k个点

        #翻转 head 到cur间的节点
        next = cur.next
        cur.next = None
        dummy = cur

        c = head.next
        pre = head
        while c:
            tem = c.next
            c.next = pre
            pre = c
            c = tem
        #head 指向下一段
        head.next = self.reverseKGroup(next,k)
        return dummy

```
