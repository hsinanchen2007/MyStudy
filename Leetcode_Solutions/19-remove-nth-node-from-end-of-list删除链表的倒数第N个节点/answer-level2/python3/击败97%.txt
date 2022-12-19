```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        first = ListNode(0)
        first.next = head
        fast = first
        while n:
            fast = fast.next
            n -= 1
        slow = first
        while fast and fast.next:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return(first.next)
        
```
第一次解链表的题目，此题的逻辑是借鉴其他人的。
个人觉得在python中链表的难点是理解链表和列表、字典的区别
链表的创建需要通过调用类，然后链表有特定的next和prev方法，head和tail能起到标识符的作用
