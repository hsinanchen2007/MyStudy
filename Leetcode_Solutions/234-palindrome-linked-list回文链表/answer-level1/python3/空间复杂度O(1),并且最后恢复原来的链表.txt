```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        # 仅用有限几个变量
        if head is None or head.next is None:
            return True
        slow = head
        fast = head
        # 快慢指针遍历
        while fast.next and fast.next.next:
            slow = slow.next        #中间节点
            fast = fast.next.next   #结尾节点
        cur = slow.next #右部分第一个节点
        # 中间节点指向None
        slow.next = None 
        pre = slow
        # 反转右半区
        while cur:
            next = cur.next
            cur.next = pre 
            pre = cur
            cur = next
        tail = pre # 保留最后一个节点
        right = pre
        left = head
        res = True
        # 检查是否是回文
        while left and right:
            if left.val != right.val:
                res = False
                break
            left = left.next
            right = right.next
        # 恢复原来的链表
        pre = tail
        cur = tail.next
        tail.next = None
        while cur:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        return res
```
