1.算法目标：遍历一遍原链表，将其拆为值小于x的和值大于等于x的两条链表。再将其合并起来，返回值小于x的链表的头节点。
2.方法：创建四个节点，两个作为新链表头节点，两个指向新链表最后一个元素用于添加元素。再用head将原链表遍历一遍，遍历时将其分割。注意合并时新链表为空的情况。
3.代码：
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        #先去除链表为空或者长度为1的情况
        if (not head) or (head.next == None):
            return head
        #small_head、large_head分别为新链表的表头，small、large分别记录新链表最后一个元素
        small_head = ListNode(-2)
        large_head = ListNode(-1)
        small = ListNode(1)
        large = ListNode(2)
        
        while head:
            if head.val<x:
                #值小于x的新链表还没有元素时，创建
                if small.next == None:
                    small.next = head
                    small_head.next = head
                #把值小于x的原链表的节点添加到新链表上
                else:
                    small.next.next = head
                    small.next = head
                
            elif head.val>=x:
                #值大于x的新链表还没有元素时，创建
                if large.next == None:
                    large.next = head
                    large_head.next = head
                #把值大于x的原链表的节点添加到新链表上
                else:
                    large.next.next = head
                    large.next = head
            head = head.next
        
        #合并两个链表，考虑其中一个为空的情况
        if small_head.next == None:
            return large_head.next
        elif large_head.next == None:
            return small_head.next
        else:
            large.next.next = None
            small.next.next = large_head.next
            return small_head.next
            
            
```
